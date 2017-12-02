#ifndef MAP_H
#define MAP_H

#include <functional>
#include <iostream>
#include <cstring>


template<typename K, typename V> class Bucket;
template<typename K, typename V> class Node;


namespace
{
  const size_t DefaultMapSize = 1024;
}


template<typename K, typename V>
class Map {
 public:

  // return true if the provided keys are equal
  using EqualsFunction = std::function<bool(const K &, const K &)>;

  // return the hash value for a provided key
  using HashFunction = std::function<int(const K &)>;

  Map(EqualsFunction equals, HashFunction hash);
  Map(EqualsFunction equals, HashFunction hash, size_t mapSize);
  ~Map();

  // insert or replace the value for the provided key
  void insert(const K &key, const V &value);

  // test whether a key exists in the map
  bool contains(const K &key);

  // lookup the value associated with the provided key
  // if the key exists, copy to *value and return true,
  // otherwise, return false
  bool lookup(const K &key, V *value);

  // remove the value associated with the provided key
  void remove(const K &key);

 private:

  EqualsFunction equals;
  HashFunction hash;
  size_t mapSize {DefaultMapSize};

  Bucket<K, V>* buckets;
};


template<typename K, typename V>
struct Node {

  Node(const K &key, const V &value) : key(key), value(value) {}
  ~Node() {}

  K key;
  V value;
  Node<K, V>* next {nullptr};
};


template<typename K, typename V>
struct Bucket {

  Bucket() {}
  ~Bucket() {}

  Node<K, V>* head {nullptr};
};


template<typename K, typename V>
Map<K, V>::Map(EqualsFunction equals, HashFunction hash) : equals(equals), hash(hash) {

  buckets = new Bucket<K, V>[mapSize];
}


template<typename K, typename V>
  Map<K, V>::Map(EqualsFunction equals, HashFunction hash, size_t mapSize) : equals(equals), hash(hash),
                                                                             mapSize(mapSize) {

  buckets = new Bucket<K, V>[mapSize];
}


template<typename K, typename V>
Map<K, V>::~Map() {
  for (size_t idx = 0; idx < mapSize; idx++) {

    Node<K, V>* curNode = buckets[idx].head;

    while (curNode != nullptr) {
      Node<K, V>* deletedNode = curNode;
      curNode = curNode->next;
      delete deletedNode;
    }
  }
  delete[] buckets;
}


template<typename K, typename V>
void Map<K, V>::insert(const K &key, const V &value) {

  size_t hashIndex = hash(key) % mapSize;
  Bucket<K, V>* bucketAtKey = buckets + hashIndex;

  Node<K, V>* newNode = bucketAtKey->head;
  if (newNode == nullptr) {
    bucketAtKey->head = new Node<K, V>(key, value);
    return;
  }

  Node<K, V>* prevNode = nullptr;

  while (newNode != nullptr) {
    if (equals(newNode->key,key)) {
      return;
    }
    prevNode = newNode;
    newNode = newNode->next;
  }

  prevNode->next = new Node<K, V>(key, value);
}


template<typename K, typename V>
bool Map<K, V>::contains(const K &key) {

  V voidArg;
  return lookup(key, &voidArg);
}


template<typename K, typename V>
bool Map<K, V>::lookup(const K &key, V *value) {

  size_t hashIndex = hash(key) % mapSize;
  Bucket<K, V>* bucketAtKey = buckets + hashIndex;
  Node<K, V>* curNode = bucketAtKey->head;

  while (curNode != nullptr) {
    if (equals(curNode->key,key)) {
      *value = curNode->value;
      return true;
    }
    curNode = curNode->next;
  }

  return false;
}


template<typename K, typename V>
void Map<K, V>::remove(const K &key) {

  size_t hashIndex = hash(key) % mapSize;
  Bucket<K, V>* bucketAtKey = buckets + hashIndex;

  /* I do this check at the beginning to prevent checking if prevNode is
     nullptr later */
  if (equals(bucketAtKey->head->key,key)) {
    Node<K, V>* head = bucketAtKey->head;
    bucketAtKey->head = bucketAtKey->head->next;
    delete head;
    return;
  }

  Node<K, V>* prevNode = bucketAtKey->head;
  Node<K, V>* curNode = bucketAtKey->head->next;

  while (curNode != nullptr) {
    if (equals(curNode->key,key)) {
      /* Here I don't have to check prevNode */
      prevNode->next = curNode->next;
      delete curNode;
      return;
    }
    prevNode = curNode;
    curNode = curNode->next;
  }
}

#endif /* MAP_H */
