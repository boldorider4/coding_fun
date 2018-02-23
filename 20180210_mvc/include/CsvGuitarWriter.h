#ifndef CSV_GUITAR_WRITER_H
#define CSV_GUITAR_WRITER_H

#include "GuitarWriter.h"
#include "Guitar.h"


namespace mvc {

  class CsvGuitarWriter : public GuitarWriter {
  public:
    CsvGuitarWriter() {};
    virtual ~CsvGuitarWriter() {};
    MvcRetval write(std::ofstream& output, const Guitar& guitar) override;
  };
}

#endif /* CSV_GUITAR_WRITER_H */
