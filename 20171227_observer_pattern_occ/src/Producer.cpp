#include "Producer.h"
#include "Observer.h"
#include <chrono>
#include <iostream>


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

  std::cout << instanceName << " - threadLoop" << std::endl;

  for (auto observer : _observers) {
    observer->onNotification(0);
  }
}


void Producer::threadLoop(Producer* const producer) {

  while (true) {

    std::this_thread::sleep_for(std::chrono::seconds(1));
    producer->notifyObservers();

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


FileChangeProducer::FileChangeProducer(const std::string& fileName) : fileName(fileName) {}


void FileChangeProducer::notifyObservers() {
}
