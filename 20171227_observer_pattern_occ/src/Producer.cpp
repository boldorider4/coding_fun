#include "Producer.h"
#include "Observer.h"
#include <chrono>


using namespace occurrenceCounter;


Producer::Producer(std::string name) : instanceName(name) {}


OccRetval Producer::addObserver(Observer& observer) {
  _observers.insert(&observer);
  return OccRetval::no_error;
}


OccRetval Producer::removeObserver(Observer& observer) {
  _observers.erase(&observer);
  return OccRetval::no_error;
}


OccRetval Producer::Start() {
  if (_thread == nullptr) {
    runThread = true;
    _thread = new std::thread(threadLoop, this);
  } else {
    return OccRetval::thread_error;
  }

  return OccRetval::no_error;
}


OccRetval Producer::Stop() {

  if (_thread != nullptr) {

    /* locking producer resources */
    std::unique_lock<std::mutex> lockThread(mtx);
    runThread = false;
    /* unlocking producer resources */
    lockThread.unlock();

    _thread->join();

    delete _thread;
    _thread = nullptr;
  } else {
    return OccRetval::thread_error;
  }

  return OccRetval::no_error;
}


void Producer::notifyObservers() {

  for (auto observer : _observers) {
    observer->onNotification(0);
  }
}

void Producer::threadLoop(Producer* const producer) {

  while (true) {

    std::this_thread::sleep_for(std::chrono::seconds(1));

    if (producer != nullptr) {
      producer->notifyObservers();
    } else {
      break;
    }

    /* locking producer resources */
    std::unique_lock<std::mutex> lockThread(producer->mtx);
    bool mustBreakLoop = !producer->runThread;
    /* unlocking producer resources */
    lockThread.unlock();

    if (mustBreakLoop) {
      break;
    }
  }
}


FileChangeProducer::FileChangeProducer(const std::string& fileName) :
  fileName(fileName),
  lastModifiedTime(expfs::last_write_time(fileName)) {}

void FileChangeProducer::notifyObservers() {

  /* get last write time*/
  auto lastWriteTime = expfs::last_write_time(fileName);

  /* convert last write time and previously stored time to std::time_t, then draw time lapse */
  std::time_t lastWriteCtime = decltype(lastWriteTime)::clock::to_time_t(lastWriteTime);
  std::time_t previousWriteCtime = decltype(lastWriteTime)::clock::to_time_t(lastModifiedTime);
  double TimeLapse = difftime(lastWriteCtime, previousWriteCtime);

  if (TimeLapse > 0) {

    lastModifiedTime = lastWriteTime;

    for (auto observer : _observers) {
      observer->onNotification(0);
    }
  }
}
