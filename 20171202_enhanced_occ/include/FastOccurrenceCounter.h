#ifndef ENHANCED_FILE_PARSER_H
#define ENHANCED_FILE_PARSER_H

#include "errorCode.h"
#include "IOccurrenceCounter.h"
#include "HashTable.h"
#include <fstream>
#include <string>


namespace OccurrenceCounter {

  class FastOccurrenceCounter : public IOccurrenceCounter {

    using StringIntMap = Map<std::string, int>;

  public:
    /* con/de-structors */
    FastOccurrenceCounter(const std::string& fileName);
    virtual ~FastOccurrenceCounter();
    FastOccurrenceCounter(const FastOccurrenceCounter& cpFastOccurrenceCounter) = delete;
    FastOccurrenceCounter(const FastOccurrenceCounter&&) = delete;
    FastOccurrenceCounter& operator=(const FastOccurrenceCounter&) = delete;
    FastOccurrenceCounter& operator=(const FastOccurrenceCounter&&) = delete;

    /* interface */
    virtual OccRetval init() override;
    virtual OccRetval countWord(int* count, const std::string& word, const bool caseInsensitive) override;
    std::string* getFileName() override;

  private:
    bool initialized {false};
    std::string fileName;
    StringIntMap parserHashTable;
    std::ifstream fileReader;
  };

}

#endif /* ENHANCED_FILE_PARSER_H */
