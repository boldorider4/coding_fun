#ifndef CMDL_PARSER_H
#define CMDL_PARSER_H

#include <string>
#include "errorCode.h"


class CmdlParser {
 public:
  /* con/de-structors */
  CmdlParser(int argc, const char* const* argv, bool debug=false);
  ~CmdlParser();
  CmdlParser(const CmdlParser&) = delete;
  CmdlParser(const CmdlParser&&) = delete;
  CmdlParser& operator=(const CmdlParser&) = delete;

  /* interface */
  OccRetval parseCmdlArguments();
  void printArgs() const;
  const char* getWord() const;
  const char* getFileName() const;
  bool getCaseInsensitive() const;

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

#endif /* CMDL_PARSER_H */
