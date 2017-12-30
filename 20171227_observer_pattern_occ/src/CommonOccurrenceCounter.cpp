#include "CommonOccurrenceCounter.h"
#include "BasicOccurrenceCounter.h"
#include "FastOccurrenceCounter.h"
#include <stdexcept>
#if ((__GNUC__ >= 5))
#include <experimental/filesystem>
#endif


namespace occurrenceCounter {

  void openFile(const std::string& fileName, std::ifstream& fileReader) {
    if (fileName.empty()) {
      throw std::invalid_argument("fileName passed to OccurrenceCounter was an empty string");
    }

    try {
      std::string filePath;

      if (fileName[0] != '/') {
        filePath = "./";
        filePath.append(fileName);
      } else {
        filePath = fileName;
      }

#if ((__GNUC__ >= 5))
      std::experimental::filesystem::path path(filePath);
      if (std::experimental::filesystem::is_regular_file(path)) {
        fileReader.open(filePath);
      }
#else
      fileReader.open(filePath);
#endif

    } catch (const std::ifstream::failure& f_e) {
      throw f_e;
    }
  }


  bool stringCompare(const std::string& searchWord, const std::string& fileWord, const bool caseInsensitive) {
    size_t sLength = searchWord.length();

    if (fileWord.length() != sLength) {
      return false;
    }

    for (size_t stridx = 0; stridx < sLength; stridx++) {
      if (searchWord[stridx] != fileWord[stridx] && (!caseInsensitive ||
                                                     ((searchWord[stridx] >= 'A' && searchWord[stridx] <= 'Z' &&
                                                       searchWord[stridx] != fileWord[stridx] - 32) ||
                                                      (searchWord[stridx] >= 'a' && searchWord[stridx] <= 'z' &&
                                                       searchWord[stridx] != fileWord[stridx] + 32)))) {
        return false;
      }
    }

    return true;
  }


  bool string_equals(const std::string& str1, const std::string& str2) {
    return stringCompare(str1, str2, false);
  }


  int string_hash(const std::string& word) {
    const int seed = 111;
    unsigned long hash = 0;
    for(size_t i = 0; i < word.length(); i++) {
      hash = (hash * seed) + word[i];
    }
    return hash;
  }


  void freeResources(std::list<IOccurrenceCounter*>& counterList) {
    for (auto counterIt : counterList) {
      if (counterIt != nullptr) {
	BasicOccurrenceCounter* basicCounterIt = dynamic_cast<BasicOccurrenceCounter*>(counterIt);
	FastOccurrenceCounter* fastCounterIt = dynamic_cast<FastOccurrenceCounter*>(counterIt);
	
	if (basicCounterIt != nullptr) {
	  delete basicCounterIt;
	} else if (fastCounterIt != nullptr) {
	  delete fastCounterIt;
	}
      }
    }
  }
}
