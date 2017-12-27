#ifndef I_OCCURRENCE_COUNTER
#define I_OCCURRENCE_COUNTER

#include "errorCode.h"
#include <string>

namespace occurrenceCounter {

  class IOccurrenceCounter {
  public:
    virtual OccRetval init() = 0;
    virtual OccRetval countWord(int* count, const std::string& word, const bool caseInsensitive) = 0;
    virtual std::string* getFileName() = 0;
  };
}

#endif /* I_OCCURRENCE_COUNTER */
