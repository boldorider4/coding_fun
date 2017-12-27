#include "BasicOccurrenceCounter.h"
#include "CommonOccurrenceCounter.h"
#include <string>
#include <cstring>


namespace occurrenceCounter {

  BasicOccurrenceCounter::BasicOccurrenceCounter(const std::string& fileName) : fileName(fileName) {
    openFile(fileName, fileReader);
  }


  BasicOccurrenceCounter::~BasicOccurrenceCounter() {
    fileReader.close();
  }


  OccRetval BasicOccurrenceCounter::init() {
    if (!fileReader.is_open()) {
      return OccRetval::file_is_not_open;
    }
    initialized = true;
    return OccRetval::no_error;
  }


  OccRetval BasicOccurrenceCounter::countWord(int* count, const std::string& word, const bool caseInsensitive) {
    if (initialized) {
      *count = 0;

      std::string fileWord;
      char fileChar;
      try {

        while (fileReader.get(fileChar)) {
          if (isalnum(fileChar)) {
            fileWord.append(1, fileChar);
          } else {
            if (stringCompare(word, fileWord, caseInsensitive)) {
              (*count)++;
            }

            fileWord.resize(0);
          }
        }

        fileReader.clear();
        fileReader.seekg(0);

      } catch (const std::ifstream::failure& e) {
        return OccRetval::file_reading_error;
      }
    } else {
      return OccRetval::not_initialized;
    }

    return OccRetval::no_error;
  }


  std::string* BasicOccurrenceCounter::getFileName() { return &fileName; }
}
