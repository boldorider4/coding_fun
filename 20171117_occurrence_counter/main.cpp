#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "cmdlParser.h"
#include "fileParser.h"
#include "errorCode.h"


int main(int argc, const char* const* argv) {

  occRetval retval;

  cmdlParser parser(argc, argv);

  try {
    retval = parser.parseCmdlArguments();
  } catch (const std::invalid_argument& ia_e) {
    std::cerr << ia_e.what() << std::endl;
    return EXIT_FAILURE;
  }

  if (retval == occRetval::must_exit) {
    return EXIT_SUCCESS;
  }

  fileParser fparser(parser.getFileName());
  int count = 0;
  retval = fparser.countWord(count, parser.getWord(), parser.getCaseInsensitive());

  if (retval == occRetval::file_is_not_open) {
    std::cerr << "File " << parser.getFileName() << " does not exist or could not be opened" << std::endl;
    return EXIT_FAILURE;
  } else if (retval == occRetval::file_reading_error) {
    std::cerr << "Error reading file" << std::endl;
    return EXIT_FAILURE;
  } else {
    std::cout << "Word " << parser.getWord() << " was found " << count << " time(s) in file " << parser.getFileName() << std::endl;
  }

  return EXIT_SUCCESS;
}
