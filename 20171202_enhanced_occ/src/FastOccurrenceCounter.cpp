#include "FastOccurrenceCounter.h"
#include "errorCode.h"
#include <string>
#if ((__GNUC__ >= 6) && defined(__clang__))
#include <experimental/filesystem>
#endif


namespace OccurrenceCounter {

  FastOccurrenceCounter::FastOccurrenceCounter(const std::string& fileName) : fileName(fileName),
                                                                              parserHashTable(string_equals,
                                                                                              string_hash) {
    if (fileName.empty()) {
      throw std::invalid_argument("fileName passed to OccurrenceCounter was an empty string");
    }

    try {
      std::string filePath;

      if (fileName[0] != '/') {
        filePath = "./";
        filePath.append(fileName);
      } else {
        filePath = fileName;
      }

#if ((__GNUC__ >= 6) && defined(__clang__))
      std::experimental::filesystem::path path(filePath);
      if (std::experimental::filesystem::is_regular_file(path)) {
        fileReader.open(filePath);
      }
#else
      fileReader.open(filePath);
#endif

    } catch (const std::ifstream::failure& f_e) {
      throw f_e;
    }
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


  bool FastOccurrenceCounter::stringCompare(const std::string& searchWord, const std::string& fileWord, const bool caseInsensitive) {
    size_t sLength = searchWord.length();

    if (fileWord.length() != sLength) {
      return false;
    }

    for (size_t stridx = 0; stridx < sLength; stridx++) {
      if (searchWord[stridx] != fileWord[stridx] && (!caseInsensitive ||
                                                     ((searchWord[stridx] >= 'A' && searchWord[stridx] <= 'Z' &&
                                                       searchWord[stridx] != fileWord[stridx] - 32) ||
                                                      (searchWord[stridx] >= 'a' && searchWord[stridx] <= 'z' &&
                                                       searchWord[stridx] != fileWord[stridx] + 32)))) {
        return false;
      }
    }

    return true;
  }


  std::string* FastOccurrenceCounter::getFileName() { return &fileName; }


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
