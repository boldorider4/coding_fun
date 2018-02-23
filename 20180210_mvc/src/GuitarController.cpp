#include "GuitarController.h"
#include "Guitar.h"
#include "errorCode.h"
#include "GuitarFactory.h"
#include <iostream>
#include <fstream>


namespace mvc {

  GuitarController::GuitarController(GuitarRepository* model) : CtrlModel(model) {}

  void GuitarController::onGuitarModelRequest(const std::string& format,
					      const std::string& model,
					      const std::string& file) {
    /* Retrieve guitars from model abstraction */
    std::vector<Guitar> guitars;
    
    MvcRetval retval = CtrlModel->getGuitarsForModel(guitars, model);
    if (retval != MvcRetval::no_error) {
      std::cerr << "[GuitarController] error: while retrieveing guitar from repository"
		<< std::endl;
    }

    outputGuitars(format, guitars);
  }

  void GuitarController::onGuitarBrandRequest(const std::string& format,
					      const std::string& brand,
					      const std::string& file) {
    /* Retrieve guitars from model abstraction */
    std::vector<Guitar> guitars;
    
    MvcRetval retval = CtrlModel->getGuitarsForBrand(guitars, brand);
    if (retval != MvcRetval::no_error) {
      std::cerr << "[GuitarController] error: while retrieveing guitar from repository"
		<< std::endl;
    }

    outputGuitars(format, guitars);
  }

  void GuitarController::outputGuitars(const std::string& format, std::vector<Guitar>& guitars) {

    GuitarWriter* writer = nullptr;

    /* Retrieve appropriate guitar writer (content negotiation) */
    MvcRetval retval = Factory::getGuitarWriterForFormat(writer, format);
    if (retval != MvcRetval::no_error || writer == nullptr) {
      std::cerr << "[GuitarController] error: failed to get guitar writer" << std::endl;
    }

    std::ofstream outputFile = std::ofstream("guitarDbOutput.txt", std::ios::out);

    for (const auto &guitarRow : guitars) {
      writer->write(outputFile, guitarRow);
    }
  }
}
