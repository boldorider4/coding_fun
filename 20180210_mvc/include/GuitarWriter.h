#ifndef GUITAR_WRITER_H
#define GUITAR_WRITER_H

#include "errorCode.h"
#include "Guitar.h"
#include <fstream>


namespace mvc {

  class GuitarWriter {
  public:
    virtual ~GuitarWriter() = default;
    virtual MvcRetval write(std::ofstream& output, const Guitar& guitar) = 0;
  };
}

#endif /* GUITAR_WRITER_H */
