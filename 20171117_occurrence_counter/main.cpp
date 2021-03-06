#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "CmdlParser.h"
#include "FileParser.h"
#include "errorCode.h"


int main(int argc, const char* const* argv) {

  OccRetval retval;

  CmdlParser parser(argc, argv);

  try {
    retval = parser.parseCmdlArguments();
  } catch (const std::invalid_argument& ia_e) {
    std::cerr << ia_e.what() << std::endl;
    return EXIT_FAILURE;
  }

  if (retval == OccRetval::must_exit) {
    return EXIT_SUCCESS;
  }

  int count = 0;

  try {
    FileParser fparser(parser.getFileName());
    retval = fparser.countWord(&count, parser.getWord(), parser.getCaseInsensitive());

    if (retval == OccRetval::file_is_not_open) {
      std::cerr << "File " << parser.getFileName() << " does not exist or could not be opened" << std::endl;
      return EXIT_FAILURE;
    } else if (retval == OccRetval::file_reading_error) {
      std::cerr << "Error reading file" << std::endl;
      return EXIT_FAILURE;
    } else {
      std::cout << "Word " << parser.getWord() << " was found " << count << " time(s) in file " << parser.getFileName() << std::endl;
    }

  } catch (const std::invalid_argument& ia_e) {
    std::cerr << ia_e.what() << std::endl;
    return EXIT_FAILURE;
  } catch (const std::ifstream::failure& f_e) {
    std::cerr << f_e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
