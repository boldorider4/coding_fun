#include "FastOccurrenceCounter.h"
#include "CommonOccurrenceCounter.h"
#include "errorCode.h"
#include <string>
#include <stdexcept>


namespace occurrenceCounter {

  FastOccurrenceCounter::FastOccurrenceCounter(const std::string& fileName) : fileName(fileName) {
    try {
      fileChangeWatchdog = new FileChangeProducer(fileName);
    } catch (const expfs::filesystem_error& fs_e) {
      throw fs_e;
    }

    try {
      openFile(fileName, fileReader);
    } catch (const std::ifstream::failure& f_e) {
      delete fileChangeWatchdog;
      throw f_e;
    }

    fileChangeWatchdog->addObserver(*this);
    fileChangeWatchdog->Start();

    parserHashTable = new StringIntMap(string_equals, string_hash);
  }


  FastOccurrenceCounter::~FastOccurrenceCounter() {
    if (fileChangeWatchdog != nullptr) {
      fileChangeWatchdog->removeObserver(*this);
      fileChangeWatchdog->Stop();
      delete fileChangeWatchdog;
    }
    if (fileReader.is_open()) {
      fileReader.close();
    }
    if (parserHashTable != nullptr) {
      delete parserHashTable;
    }
  }


  OccRetval FastOccurrenceCounter::init() {

    if (!fileReader.is_open()) {
      return OccRetval::file_is_not_open;
    } else {

      std::string fileWord;
      char fileChar;

      try {
        while (fileReader.get(fileChar)) {
          if (isalnum(fileChar)) {
            fileWord.append(1, fileChar);
          } else {

            int wordCount;

            if (parserHashTable->lookup(fileWord, &wordCount)) {
              parserHashTable->insert(fileWord, ++wordCount);
            } else {
              parserHashTable->insert(fileWord, 1);
            }

            fileWord.resize(0);
          }
        }

	fileReader.clear();
	fileReader.seekg(0);

      } catch (const std::ifstream::failure& e) {
        fileReader.close();
        return OccRetval::file_reading_error;
      }
    }

    initialized = true;
    return OccRetval::no_error;
  }


  OccRetval FastOccurrenceCounter::countWord(int* count, const std::string& word, const bool caseInsensitive) {

    if (initialized) {
      *count = 0;
      parserHashTable->lookup(word, count);
      return OccRetval::no_error;
    } else {
      return OccRetval::not_initialized;
    }
  }


  std::string* FastOccurrenceCounter::getFileName() { return &fileName; }


  void FastOccurrenceCounter::onNotification(int token) {

    fileReader.close();
    openFile(fileName, fileReader);
    parserHashTable->clear();
    init();
  }
}
