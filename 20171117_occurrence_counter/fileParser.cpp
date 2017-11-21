#include <stdexcept>
#include <string>
#include <cstring>
#include "fileParser.h"


FileParser::FileParser(const char* const fileName) {
  if (fileName == nullptr) {
    throw std::invalid_argument("fileName passed to FileParser was nullptr");
  }

  try {
    if (fileName != nullptr && fileName[0] != '/') {
      char* relativeFileName = new char[strlen(fileName) + 2];
      relativeFileName[0] = '.';
      relativeFileName[1] = '/';
      strcpy(relativeFileName+2, fileName);
      fileReader.open(relativeFileName);
    } else {

      fileReader.open(fileName);
    }
  } catch (const std::ifstream::failure& f_e) {
    throw f_e;
  }
}


FileParser::~FileParser() {
  fileReader.close();
}


OccRetval FileParser::countWord(int& count, const char* const word, const bool caseInsensitive) {
  count = 0;

  if (!fileReader.is_open()) {
    return OccRetval::file_is_not_open;
  } else {
    std::vector<char> fileWord;
    char fileChar;
    try {
      while (fileReader.get(fileChar)) {
        if (isalnum(fileChar)) {
          fileWord.push_back(fileChar);
        } else {
          if (stringCompare(word, fileWord, caseInsensitive)) {
            count++;
          }

          fileWord.resize(0);
        }
      }

      fileReader.seekg(0);
    } catch (const std::ifstream::failure& e) {
      return OccRetval::file_reading_error;
    }
  }

  return OccRetval::no_error;
}


bool FileParser::stringCompare(const char* const searchWord, const std::vector<char>& fileWord, const bool caseInsensitive) {
  size_t sLength = strlen(searchWord);

  if (fileWord.size() != sLength) {
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
