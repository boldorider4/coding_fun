#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include "errorCode.h"
#include "IOccurrenceCounter.h"
#include <fstream>
#include <string>


namespace OccurrenceCounter {

  class BasicOccurrenceCounter : public IOccurrenceCounter {
  public:
    /* con/de-structors */
    BasicOccurrenceCounter(const std::string& fileName);
    virtual ~BasicOccurrenceCounter();
    BasicOccurrenceCounter(const BasicOccurrenceCounter& cpBasicOccurrenceCounter) = delete;
    BasicOccurrenceCounter(const BasicOccurrenceCounter&&) = delete;
    BasicOccurrenceCounter& operator=(const BasicOccurrenceCounter&) = delete;
    BasicOccurrenceCounter& operator=(const BasicOccurrenceCounter&&) = delete;

    /* interface */
    virtual OccRetval init() override;
    virtual OccRetval countWord(int* count, const std::string& word, const bool caseInsensitive) override;
    std::string* getFileName() override;

  private:
    bool initialized {false};
    std::string fileName;
    std::ifstream fileReader;
  };

}

#endif /* FILE_PARSER_H */
