#ifndef GUITAR_FACTORY_H
#define GUITAR_FACTORY_H

#include "errorCode.h"
#include "GuitarWriter.h"
#include "CsvGuitarWriter.h"
#include "NullGuitarWriter.h"
#include <string>


namespace Factory {

  mvc::MvcRetval getGuitarWriterForFormat(mvc::GuitarWriter* out, const std::string& format) {
    if (format == "csv") {
      out = new mvc::CsvGuitarWriter();
      return mvc::MvcRetval::no_error;
    } else {
      throw "invalid format";
    }

    return mvc::MvcRetval::error;
  }
}

#endif /* GUITAR_FACTORY_H */
