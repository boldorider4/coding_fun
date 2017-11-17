#include <cstdlib>
#include <iostream>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>


int main(int argc, char** argv) {
  boost::program_options::options_description options("Options");

  options.add_options()
    ("help,h", "produce help")
    ("word,w", "word specifier")
    ("file,f", "path to file")
    ("icase,i", "enable case-insensitive");

  boost::program_options::variables_map vm;
  store(boost::program_options::parse_command_line(argc, argv, options), vm);

  if (vm.count("help") || argc == 1) {
    std::cout << options;
    return EXIT_SUCCESS;
  }

  return EXIT_SUCCESS;
}
