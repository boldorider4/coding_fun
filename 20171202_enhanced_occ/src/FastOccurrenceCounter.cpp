#include "FastOccurrenceCounter.h"
#include "CommonOccurrenceCounter.h"
#include "errorCode.h"
#include <string>


namespace occurrenceCounter {

  FastOccurrenceCounter::FastOccurrenceCounter(const std::string& fileName) : fileName(fileName),
                                                                              parserHashTable(string_equals,
                                                                                              string_hash) {
    openFile(fileName, fileReader);
  }


  FastOccurrenceCounter::~FastOccurrenceCounter() {}


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

            if (parserHashTable.lookup(fileWord, &wordCount)) {
              parserHashTable.insert(fileWord, ++wordCount);
            } else {
              parserHashTable.insert(fileWord, 1);
            }

            fileWord.resize(0);
          }
        }

      } catch (const std::ifstream::failure& e) {
        fileReader.close();
        return OccRetval::file_reading_error;
      }
    }

    fileReader.close();
    initialized = true;
    return OccRetval::no_error;
  }


  OccRetval FastOccurrenceCounter::countWord(int* count, const std::string& word, const bool caseInsensitive) {

    if (initialized) {
      *count = 0;
      parserHashTable.lookup(word, count);
      return OccRetval::no_error;
    } else {
      return OccRetval::not_initialized;
    }
  }


  std::string* FastOccurrenceCounter::getFileName() { return &fileName; }
}
