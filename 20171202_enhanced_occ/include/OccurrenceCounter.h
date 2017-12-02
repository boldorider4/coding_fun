#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <fstream>
#include <string>
#include "errorCode.h"


namespace OccurrenceCounter {

  class OccurrenceCounter {
  public:
    /* con/de-structors */
    OccurrenceCounter(const std::string& fileName);
    virtual ~OccurrenceCounter();
    OccurrenceCounter(const OccurrenceCounter& cpOccurrenceCounter) = delete;
    OccurrenceCounter(const OccurrenceCounter&&) = delete;
    OccurrenceCounter& operator=(const OccurrenceCounter&) = delete;
    OccurrenceCounter& operator=(const OccurrenceCounter&&) = delete;

    /* interface */
    virtual OccRetval init();
    virtual OccRetval countWord(int* count, const std::string& word, const bool caseInsensitive);
    std::string* getFileName();

  protected:
    std::string fileName;
    std::ifstream fileReader;
    bool initialized {false};

    static bool stringCompare(const std::string& searchWord, const std::string& fileWord, const bool caseInsensitive);
  };

}

#endif /* FILE_PARSER_H */
