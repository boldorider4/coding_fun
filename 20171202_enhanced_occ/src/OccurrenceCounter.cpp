#include <stdexcept>
#include <string>
#include <cstring>
#include "OccurrenceCounter.h"
#if ((__GNUC__ >= 6) && defined(__clang__))
#include <experimental/filesystem>
#endif


namespace OccurrenceCounter {

  BasicOccurrenceCounter::BasicOccurrenceCounter(const std::string& fileName) : fileName(fileName) {
    if (fileName.empty()) {
      throw std::invalid_argument("fileName passed to BasicOccurrenceCounter was an empty string");
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


  bool BasicOccurrenceCounter::stringCompare(const std::string& searchWord, const std::string& fileWord, const bool caseInsensitive) {
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
}
