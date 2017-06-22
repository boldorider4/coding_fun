#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>

int main(int argv, char* argc[])
{
  std::ifstream fileHandler("foo.txt", std::ifstream::in);
  std::istream_iterator<std::string> in_s {fileHandler};

  if (argv > 1 && !(static_cast<std::string>(argc[1])).compare("iter")) {
    std::istream_iterator<std::string> eos;
    std::ostream_iterator<std::string> stdout_it {std::cout};

    std::cerr << "copy is going to be executed!" << std::endl;
    for (auto cnt = 0; cnt < 500000; cnt++) {
      std::copy(in_s, eos, stdout_it);
      fileHandler.clear();
      fileHandler.seekg(0, std::ios::beg);
    }
  } else if (argv > 1 && !(static_cast<std::string>(argc[1])).compare("while")) {
    std::cerr << "while loop is going to be executed!" << std::endl;
    for (auto cnt = 0; cnt < 500000; cnt++) {
      while (!fileHandler.eof()) {
        std::cout << *in_s;
        ++in_s;
      }
      fileHandler.clear();
      fileHandler.seekg(0, std::ios::beg);
    }
  }

  fileHandler.close();
  std::cout << std::endl;
}
