#ifndef GUITAR_CONTROLLER_H
#define GUITAR_CONTROLLER_H

#include "GuitarRepository.h"
#include <string>


namespace mvc {
  
  class GuitarController {
  public:
    GuitarController(GuitarRepository* model);
    ~GuitarController() = default;

    void onGuitarModelRequest(const std::string& format,
			      const std::string& model,
			      const std::string& file);

    void onGuitarBrandRequest(const std::string& format,
			      const std::string& model,
			      const std::string& file);

  private:
    static void outputGuitars(const std::string& format, std::vector<Guitar>& guitars);

    GuitarRepository* CtrlModel;
  };
}

#endif /* GUITAR_CONTROLLER_H */
