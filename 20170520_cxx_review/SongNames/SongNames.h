/* Missing include guards */

#include <string>
#include <vector>

#include "CoupleCollection.h"
#include <map>

class SongNames : public CoupleCollection<std::string>
{
public:
  SongNames();
  SongNames(std::vector<std::pair<std::string, std::string>> initialList);
  /* better to make the destructor virtual */
  ~SongNames(){};

  /* I prefer not to have parameter names in headers for maintainability */
  bool findSimilarKey(const std::string& key, std::string& result) const;
  bool findValue(const std::string& key, std::string& result) const;
  void listKeys(void) const;
};
