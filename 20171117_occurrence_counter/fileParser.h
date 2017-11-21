#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <fstream>
#include <vector>
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

  bool stringCompare(const char* const searchWord, const std::vector<char>& fileWord, const bool caseInsensitive);
};

#endif /* FILE_PARSER_H */
