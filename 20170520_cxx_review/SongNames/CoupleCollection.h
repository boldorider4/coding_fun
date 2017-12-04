/* I would avoid pragmas if they're not strictly necessary */
/* Also, include guards are there */
#pragma once

#ifndef _KEYVALUE_H
#define _KEYVALUE_H

#include <algorithm>

/* bad practice to write definition in header since compiler will inline
   and will enforce compilation of modules that include header when code
   is maintained */
template <typename _T_>
class CoupleCollection
{
public:
  CoupleCollection()
    : m_list(0)
  {
  }

  /* minor note: this looks like std::map<> */
  _T_ getValue(const std::string& key) const
  {
    /* this will only work with strings and char* (o compatible constructors) */
    _T_ resultString = "not found";
    for (auto& item : m_list)
    {
      if (key == item.first)
      {
        resultString = item.second;
      }
    }
    return resultString;
  }

  void addPair(const std::string& key, _T_ value)
  {
    _T_ result = getValue(key);
    /* would prevent correct behavior if added value was indeed 'not found' */
    /* better to return exception or implement a different mechanism */
    if (result == "not found")
    {
      m_list.push_back(make_pair(key, value));
    }
    else
    {
      for (auto& item : m_list)
      {
        if (key == item.first)
          item.second = value;
      }
    }
  }
  /* better to pass const std::string& */
  void removeKey(const std::string key)
  {
    static int count = 0;

    auto it = std::find_if(m_list.begin(), m_list.end(),
                           [key](const std::pair<std::string, std::string>& item) {
                             return key == item.first;
                             count++;
                           });
    if (it != m_list.end())
      m_list.erase(it);
  }
/* this should be protected */
public:
  std::vector<std::pair<std::string, _T_>> m_list;
};

/* this should be in the beginning (readability killer) */
#include <string>
#include <vector>
#endif /* PROJECT_KEY_H */
