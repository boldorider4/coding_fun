#ifndef PRODUCER_H
#define PRODUCER_H

#include "errorCode.h"
#include "Observer.h"
#include <set>
#include <thread>
#include <mutex>
#include <string>
#if (__GNUC__ < 5)
#error This application requires g++ supporting experimental/filesystem
#else
#include <experimental/filesystem>
#endif


using namespace occurrenceCounter;


class Producer {
 public:
  Producer() = default;
  Producer(std::string name);
  Producer(const Producer&) = delete;
  Producer(const Producer&&) = delete;
  Producer& operator=(const Producer&) = delete;
  Producer& operator=(const Producer&&) = delete;
  virtual ~Producer() = default;

  OccRetval addObserver(Observer& observer);
  OccRetval removeObserver(Observer& observer);

  OccRetval Start();
  OccRetval Stop();

 protected:
  std::set<Observer*>   _observers;
  std::mutex            mtx;
  bool                  runThread{false};

 private:
  std::string           instanceName{"NONAME"};
  std::thread*          _thread{nullptr};

  virtual void notifyObservers();
  static void threadLoop(Producer* const producer);
};


namespace expfs = std::experimental::filesystem;

class FileChangeProducer : public Producer {
 public:
  FileChangeProducer(const std::string& fileName);
  FileChangeProducer(const FileChangeProducer&) = delete;
  FileChangeProducer(const FileChangeProducer&&) = delete;
  FileChangeProducer(FileChangeProducer&&) = default;
  FileChangeProducer& operator=(const FileChangeProducer&) = delete;
  FileChangeProducer& operator=(const FileChangeProducer&&) = delete;
  virtual ~FileChangeProducer() = default;

 private:
  std::string fileName;
  expfs::file_time_type lastModifiedTime;

  virtual void notifyObservers();
};

#endif /* PRODUCER_H */
