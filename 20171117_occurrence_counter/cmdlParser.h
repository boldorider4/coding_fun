#ifndef CMDL_PARSER_H
#define CMDL_PARSER_H

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include "errorCode.h"


class cmdlParser {
 public:
  /* con/de-structors */
  cmdlParser(int argc, const char* const* argv, bool debug);
  virtual ~cmdlParser();
  cmdlParser(const cmdlParser&) = delete;
  cmdlParser(const cmdlParser&&) = delete;
  cmdlParser& operator=(const cmdlParser&) = delete;

  /* interface */
  occRetval parseCmdlArguments();
  void printArgs() const;
  const char* getWord() const { return word; }
  const char* getFileName() const { return fileName; }
  bool getCaseInsensitive() const { return caseInsensitive; }

 private:
  static const std::string invalidArgumentMessage;
  const int argc;
  const char* const* const argv;
  /* store options */
  bool caseInsensitive;
  /* cache allowed command line parameters */
  const char* word;
  const char* fileName;


  void printHelp() const;
};


cmdlParser::cmdlParser(int argc, const char* const* argv, bool debug=false) : argc(argc), argv(argv),
                                                                              caseInsensitive(false),
                                                                              word(nullptr), fileName(nullptr) {
  if (debug) {
    std::cout << "This is developed with c++11 stdlib!" << std::endl;
    std::cout << "argc " << argc << std::endl;
    for (auto arg_cnt = 0; arg_cnt < argc; arg_cnt++) {
      std::cout << "argv[" << arg_cnt << "] '" << argv[arg_cnt] << "'" << std::endl;
    }
  }
}


cmdlParser::~cmdlParser() {}


occRetval cmdlParser::parseCmdlArguments() {

  bool mustPrintHelp = false;

  for (auto arg_cnt = 1; arg_cnt < argc; arg_cnt++) {
    const char* argv_scanner = argv[arg_cnt];

    if (argv_scanner[0] != '-' || argv_scanner[2] != '\0') {

      throw std::invalid_argument(invalidArgumentMessage);
    } else {

      switch(argv_scanner[1]) {
      case 'h':
        mustPrintHelp = true;
        break;
      case 'w':
        word = argv[++arg_cnt];
        break;
      case 'f':
        fileName = argv[++arg_cnt];
        break;
      case 'i':
        caseInsensitive = true;
        break;
      default:
        throw std::invalid_argument(invalidArgumentMessage);
      }
    }
  }

  if (argc == 1 || mustPrintHelp) {
    printHelp();
    return occRetval::must_exit;
  }

  return occRetval::no_error;
}


void cmdlParser::printArgs() const {
  if (word != nullptr) {
    std::cout << "word: " << word << std::endl;
  }
  if (fileName != nullptr) {
    std::cout << "filename: " << fileName << std::endl;
  }
  std::cout << "caseInsensitive: " << caseInsensitive << std::endl;
}


void cmdlParser::printHelp() const {
  std::cout << "Options:\n";
  std::cout << " -h: print this usage text\n";
  std::cout << " -w: specifies the word to search for\n";
  std::cout << " -f: path to a file\n";
  std::cout << " -i: perform case-insensitive comparison" << std::endl;
}


const std::string cmdlParser::invalidArgumentMessage{"Invalid command line parameters"};

#endif /* CMDL_PARSER_H */
