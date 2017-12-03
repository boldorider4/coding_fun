#include "HashTable.h"
#include <string>
#include <iostream>

using StringIntMap = Map<std::string, int>;

bool string_equals(const std::string& str1, const std::string& str2) {
  return !str1.compare(str2);
}

int string_hash(const std::string& word) {
   const int seed = 111;
   unsigned long hash = 0;
   for(size_t i = 0; i < word.length(); i++)
   {
      hash = (hash * seed) + word[i];
   }
   return hash;
}

int main() {
  StringIntMap name_age_map(string_equals, string_hash);
  name_age_map.insert("Gino Sorbillo", 30);
  name_age_map.insert("Ciro Taximan", 65);
  name_age_map.insert("Martino Gilgengo", 39);
  name_age_map.insert("Savior Countryside", 34);

  int age = 0;
  bool found = name_age_map.lookup("Savior Countryside", &age);

  if (found) {
    std::cout << "Savior Countryside's age " << age << std::endl;
  } else {
    std::cout << "Savior Countryside was not found" << std::endl;
  }

  age = 0;
  found = name_age_map.lookup("Gino Sorbillo", &age);

  if (found) {
    std::cout << "Gino Sorbillo's age " << age << std::endl;
  } else {
    std::cout << "Gino Sorbillo was not found" << std::endl;
  }

  std::cout << "is Gino Sorbillo in the list? " << name_age_map.contains("Gino Sorbillo") << std::endl;
  std::cout << "is Giacomo Tommaso in the list? " << name_age_map.contains("Giacomo Tommaso") << std::endl;

  name_age_map.insert("Gino Sorbillo", 70);

  age = 0;
  found = name_age_map.lookup("Gino Sorbillo", &age);

  std::cout << "Re-inserting Gino Sorbillo's age" << std::endl;
  if (found) {
    std::cout << "Gino Sorbillo's age " << age << std::endl;
  } else {
    std::cout << "Gino Sorbillo was not found" << std::endl;
  }

  name_age_map.remove("Gino Sorbillo");
  std::cout << "After removing Gino Sorbillo fron the table, is he stil in the list? " <<
    name_age_map.contains("Gino Sorbillo") << std::endl;

  return 0;
}
