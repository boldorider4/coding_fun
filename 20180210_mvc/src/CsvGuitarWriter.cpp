#include "CsvGuitarWriter.h"
#include "Guitar.h"
#include <string>
#include <iostream>


namespace mvc {

  MvcRetval CsvGuitarWriter::write(std::ofstream& output, const Guitar& guitar) {

    if (output.is_open()) {
      output << guitar.brand << ", "
	     << guitar.model << ", "
	     << guitar.nStrings << ", ";
      
      for (auto string = 0; string < guitar.nStrings; string ++) {
	output << guitar.stringGauge[string] << ", ";
      }
      
      output << guitar.topWood << ", "
	     << guitar.bodyWood << ", "
	     << guitar.neckWood << ", "
	     << guitar.neckJointType << ", "
	     << guitar.bridgeType;
      
      return MvcRetval::no_error;
    }

    std::cerr << "[CsvGuitarWriter] error: output stream is not open"
	      << std::endl;
    return MvcRetval::error;
  }
}
