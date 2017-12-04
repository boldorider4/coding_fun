#include <iostream>
#include <cassert>

#include "SongNames.h"

/* it would be interesting to test addPair("whatever", "not found") */

void test_remove()
{
  SongNames titles;
  titles.addPair("hello", "world");
  assert(titles.getValue("hello") == std::string("world"));
  titles.removeKey("hello");
  assert(titles.getValue("hello") == std::string("not found"));
}

void test_insert()
{
  SongNames myTest;


  myTest.addPair("hello", "world");
  assert(myTest.getValue("hello") == std::string("world"));
  std::cerr << myTest.getValue("hello") << std::endl;
  myTest.addPair("hello", "moon");
  assert(myTest.getValue("hello") == std::string("moon"));
  std::cerr << myTest.getValue("hello") << std::endl;
  std::cout << myTest.getValue("non existent") << std::endl;
  assert(std::string("not found") == myTest.getValue("non existent"));
}

void test_remove_2()
{
  SongNames titles;
  titles.addPair("hello", "world");
  assert(titles.getValue("hello") == std::string("world"));
  titles.removeKey("hello");
  assert(titles.getValue("hello") == std::string("not found"));
  titles.removeKey("hello");
  assert(titles.getValue("hello") == std::string("not found"));
}

void test_find()
{
  SongNames titles;
  titles.addPair("hello", "world");
  std::string dummy;
  assert(false == titles.findSimilarKey("moon", dummy));
  std::cout << dummy << "\n";
  assert(true == titles.findSimilarKey("wor", dummy));
  std::cout << dummy << "\n";
}

void test_list()
{
  SongNames titles;
  titles.addPair("hello", "world");
  titles.addPair("answer", "42");
  titles.addPair("Answer more", "42^2");
  titles.addPair("wrong", "right");
  titles.addPair("0", "zero");
  titles.addPair("zero", "0");
  titles.listKeys();
}

int main()
{
  test_insert();
  test_remove();
  test_remove();
  test_find();
  test_list();
  return 0;
}
