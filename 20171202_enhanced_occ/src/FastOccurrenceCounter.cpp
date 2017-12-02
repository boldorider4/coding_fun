#include "FastOccurrenceCounter.h"
#include "errorCode.h"
#include <string>


namespace OccurrenceCounter {

  FastOccurrenceCounter::FastOccurrenceCounter(const std::string& fileName) : OccurrenceCounter(fileName),
                                                                              parserHashTable(string_equals,
                                                                                              string_hash) {
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
        return OccRetval::file_reading_error;
      }
    }

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


  bool FastOccurrenceCounter::string_equals(const std::string& str1, const std::string& str2) {
    return stringCompare(str1, str2, false);
  }


  int FastOccurrenceCounter::string_hash(const std::string& word) {
    const int seed = 111;
    unsigned long hash = 0;
    for(size_t i = 0; i < word.length(); i++) {
      hash = (hash * seed) + word[i];
    }
    return hash;
  }

}
