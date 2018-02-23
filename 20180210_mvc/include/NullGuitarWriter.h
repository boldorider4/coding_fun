#ifndef NULL_GUITAR_WRITER_H
#define NULL_GUITAR_WRITER_H

#include "GuitarWriter.h"
#include "Guitar.h"


namespace mvc {

  class NullGuitarWriter : public GuitarWriter {

    NullGuitarWriter() = default;
    virtual ~NullGuitarWriter() = default;
    MvcRetval write(std::ofstream& output, const Guitar& guitar) {
      return MvcRetval::no_error;
    }
  };
}

#endif /* NULL_GUITAR_WRITER_H */
