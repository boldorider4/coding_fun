#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <iostream>
#include "InteractiveConsole.h"


namespace occurrenceCounter {


  OccRetval parseInteractiveArguments(std::string* parsedString) {
    return parseInteractiveArguments(parsedString, nullptr);
  }


  OccRetval parseInteractiveArguments(std::string* parsedString, bool* caseInsensitive) {

    std::cout << "option> ";

    std::string argLine;
    std::getline(std::cin, argLine);

    if (argLine.empty()) {
      return OccRetval::no_error;
    }

    std::stringstream argStream(argLine);
    std::istream_iterator<std::string> argStreamBeg(argStream);
    std::istream_iterator<std::string> argStreamBegEnd;
    std::vector<std::string> args(argStreamBeg, argStreamBegEnd);

    if (!args.size()) {
      return OccRetval::no_error;
    } else if (args[0].length() != 1) {
      printInvalidMessage();
      return OccRetval::no_error;
    } else switch(args[0][0]) {
      case 'h':
        if (args.size() != 1) {
          printHelp();
          break;
        }
        printHelp();
        break;
      case 's':
        if (caseInsensitive != nullptr) {
          *caseInsensitive = false;
        }
        if (args.size() == 2) {
          *parsedString = args[1];
        } else if (args.size() == 3 && args[1] == "i" && caseInsensitive != nullptr) {
          *caseInsensitive = true;
          *parsedString = args[2];
        } else {
          printInvalidMessage();
          break;
        }
        return OccRetval::word_parsed;
      case 'f':
        if (args.size() != 2) {
          printInvalidMessage();
          break;
        }
        *parsedString = args[1];
        return OccRetval::file_parsed;
      case 'q':
        return OccRetval::must_exit;
      default:
        printInvalidMessage();
      }

    return OccRetval::no_error;
  }


  void printInvalidMessage() {
    std::cerr << "invalid command" << std::endl;
  }


  void printWelcomeMessage() {
    std::cout << "welcome to the interactive occurrence counter" << std::endl;
    printHelp();
  }

  void printHelp() {
    std::cout << " f: open/read from a new file\n"
              << " s: search for a word\n"
              << " h: show this help\n"
              << " q: quit" << std::endl;
  }
}
