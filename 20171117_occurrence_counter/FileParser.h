#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <fstream>
#include <vector>
#include "errorCode.h"


class FileParser {
 public:
  /* con/de-structors */
  FileParser(const char* const fileName);
  virtual ~FileParser();
  FileParser(const FileParser&) = delete;
  FileParser(const FileParser&&) = delete;
  FileParser& operator=(const FileParser&) = delete;

  /* interface */
  OccRetval countWord(int& count, const char* const word, const bool caseInsensitive);

 private:
  std::ifstream fileReader;

  bool stringCompare(const char* const searchWord, const std::vector<char>& fileWord, const bool caseInsensitive);
};

#endif /* FILE_PARSER_H */
