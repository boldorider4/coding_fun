#include <stdexcept>
#include <iostream>
#include "CmdlParser.h"


CmdlParser::CmdlParser(int argc, const char* const* argv, bool debug) : argc(argc), argv(argv),
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


OccRetval CmdlParser::parseCmdlArguments() {

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
    return OccRetval::must_exit;
  } else if (argc == 2 || word == nullptr || fileName == nullptr) {
    throw std::invalid_argument(invalidArgumentMessage);
  }

  return OccRetval::no_error;
}


const char* CmdlParser::getWord() const { return word; }


const char* CmdlParser::getFileName() const { return fileName; }


bool CmdlParser::getCaseInsensitive() const { return caseInsensitive; }


void CmdlParser::printArgs() const {
  if (word != nullptr) {
    std::cout << "word: " << word << std::endl;
  }
  if (fileName != nullptr) {
    std::cout << "filename: " << fileName << std::endl;
  }
  std::cout << "caseInsensitive: " << caseInsensitive << std::endl;
}


void CmdlParser::printHelp() const {
  std::cout << "Options:\n"
            << " -h: print this usage text\n"
            << " -w: specifies the word to search for\n"
            << " -f: path to a file\n"
            << " -i: perform case-insensitive comparison" << std::endl;
}


const std::string CmdlParser::invalidArgumentMessage{"Invalid command line parameters"};
