#include <iostream>
#include "SongNames.h"

/* in my opinion it's bad practice to use namespace std */
using namespace std;

SongNames::SongNames()
{
}

SongNames::SongNames(std::vector<std::pair<string, string>> initialList)
{
  /* should use std::vector::size_type instead of unsigned int */
  /* also, for consistency, why not use for (auto...)? */
  for (unsigned int i = 0U; i < initialList.size(); ++i)
  {
    addPair(initialList[i].first, initialList[i].second);
  }
}

/* findSimilarKey and findValue are identical
/* would be better to call this findSimilarValue */
bool SongNames::findSimilarKey(const std::string& key, std::string& result) const
{
  auto found = std::find_if(m_list.begin(), m_list.end(),
                            [key](const std::pair<std::string, std::string>& value) {
                              /* better  return value.second.compare(0, key.length(), key) == 0 */
                              if (value.second.compare(0, key.length(), key) == 0)
                              {
                                return true;
                              }
                              return false;
                            });
  if (found != m_list.end())
  {
    result = found->second;
    return true;
  }
  /* same comment about the bad 'not found' mechanism */
  result = "not found";
  return false;
}

/* I think you meant to differentiate findValue from findSimilarKey */
bool SongNames::findValue(const std::string& key, std::string& result) const
{
  auto found = std::find_if(m_list.begin(), m_list.end(),
                            [key](const std::pair<std::string, std::string>& value) {
                              /* same as above */
                              if (value.second.compare(0, key.length(), key) == 0)
                              {
                                return true;
                              }
                              return false;
                            });
  if (found != m_list.end())
  {
    result = found->second;
    return true;
  }
  result = "not found";
  return false;
}

void SongNames::listKeys(void) const
{
  for (const auto& item : m_list)
  {
    std::cout << "" << item.first << " := " << item.second;
    std::cout << std::endl;
  }
}
