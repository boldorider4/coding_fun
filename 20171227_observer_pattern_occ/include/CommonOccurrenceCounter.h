#ifndef COMMON_OCCURRENCE_COUNTER_H
#define COMMON_OCCURRENCE_COUNTER_H

#include "IOccurrenceCounter.h"
#include <fstream>
#include <string>
#include <list>


namespace occurrenceCounter {

  void openFile(const std::string& fileName, std::ifstream& fileReader);
  bool stringCompare(const std::string& searchWord, const std::string& fileWord, const bool caseInsensitive);
  bool string_equals(const std::string& str1, const std::string& str2);
  int string_hash(const std::string& word);
  void freeResources(std::list<IOccurrenceCounter*>& counterList);
}

#endif /* COMMON_OCCURRENCE_COUNTER_H */
