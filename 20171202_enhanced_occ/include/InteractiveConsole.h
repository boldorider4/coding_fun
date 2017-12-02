#ifndef CMDL_PARSER_H
#define CMDL_PARSER_H

#include <string>
#include "errorCode.h"


namespace OccurrenceCounter {

  OccRetval parseInteractiveArguments(std::string* parsedString);
  OccRetval parseInteractiveArguments(std::string* parsedString, bool* caseInsensitive);
  void printWelcomeMessage();
  void printHelp();
  void printInvalidMessage();
}

#endif /* CMDL_PARSER_H */
