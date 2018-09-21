#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>


int median(int argv, char* argc[])
{
  std::ifstream inputFile;
  std::ios_base::iostate exceptionMask = inputFile.exceptions() | std::ios::failbit;
  inputFile.exceptions(exceptionMask);

  try {
    inputFile.open(argc[1]);
  } catch (std::ios_base::failure& fail) {
    std::cerr << "error: " << argc[1] << ": " << std::strerror(errno) << std::endl;
    return 0;
  }
  
  inputFile.close();
  return 0;
}
