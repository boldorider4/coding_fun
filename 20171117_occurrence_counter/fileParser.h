#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <fstream>
#include <string>
#include <cstring>
#include "errorCode.h"


class fileParser {
 public:
  /* con/de-structors */
  fileParser(const char* const fileName);
  virtual ~fileParser();
  fileParser(const fileParser&) = delete;
  fileParser(const fileParser&&) = delete;
  fileParser& operator=(const fileParser&) = delete;

  /* interface */
  occRetval countWord(int& count, const char* const word, const bool caseInsensitive);

 private:
  std::ifstream fileReader;

  bool stringCompare(const char* const searchWord, const char* const fileWord, const bool caseInsensitive);
};


fileParser::fileParser(const char* const fileName) {
  try {
    fileReader.open(fileName);
  } catch (const std::ifstream::failure& e) {}
}


fileParser::~fileParser() {
  fileReader.close();
}


occRetval fileParser::countWord(int& count, const char* const word, const bool caseInsensitive) {
  count = 0;

  if (!fileReader.is_open()) {
    return occRetval::file_is_not_open;
  } else {
    std::string fileWord;
    try {
      while (fileReader >> fileWord) {
        if (stringCompare(word, fileWord.c_str(), caseInsensitive)) {
          count++;
        }
      }

      fileReader.seekg(0);
    } catch (const std::ifstream::failure& e) {
      return occRetval::file_reading_error;
    }
  }

  return occRetval::no_error;
}


bool fileParser::stringCompare(const char* const searchWord, const char* const fileWord, const bool caseInsensitive) {
  size_t sLength = strlen(searchWord);

  for (size_t stridx = 0; stridx < sLength; stridx++) {
    if (searchWord[stridx] != fileWord[stridx] && (!caseInsensitive ||
                                                   ((searchWord[stridx] >= 'A' && searchWord[stridx] <= 'Z' &&
                                                     searchWord[stridx] != fileWord[stridx] - 32) ||
                                                    (searchWord[stridx] >= 'a' && searchWord[stridx] <= 'z' &&
                                                     searchWord[stridx] != fileWord[stridx] + 32)))) {
      return false;
    }
  }

  if (fileWord[sLength] != '\0') {
    return false;
  }

  return true;
}

#endif /* FILE_PARSER_H */
