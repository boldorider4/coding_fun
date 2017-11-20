#include <string>
#include <cstring>
#include "fileParser.h"


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
