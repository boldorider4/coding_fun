#ifndef ENHANCED_FILE_PARSER_H
#define ENHANCED_FILE_PARSER_H

#include "OccurrenceCounter.h"
#include "HashTable.h"
#include <string>


namespace OccurrenceCounter {
  
  class FastOccurrenceCounter : public OccurrenceCounter {

    using StringIntMap = Map<std::string, int>;

  public:
    FastOccurrenceCounter(const std::string& fileName);
    virtual ~FastOccurrenceCounter();
    FastOccurrenceCounter(const FastOccurrenceCounter& enhancedFileParser) = delete;
    FastOccurrenceCounter(const FastOccurrenceCounter&&) = delete;
    FastOccurrenceCounter& operator=(const FastOccurrenceCounter&) = delete;
    FastOccurrenceCounter& operator=(const FastOccurrenceCounter&&) = delete;

    /* extended functionality */
    virtual OccRetval init() override;
    virtual OccRetval countWord(int* count, const std::string& word, const bool caseInsensitive) override;

  private:
    StringIntMap parserHashTable;

    static bool string_equals(const std::string& str1, const std::string& str2);
    static int string_hash(const std::string& word);
  };

}

#endif /* ENHANCED_FILE_PARSER_H */
