Hi Jack,

Here's the second exercise.

Hash-tables are data structures that map an unique key to a value.
Such a data structure can be the reference implementation for std::unordered_map.

Your task is to implement a generic hash-table.

A hash-table can be seen as a simple large array where one key is mapped to an index in this array by a hash function.
More formally,
index = hash-function(key)
value = hash-table[index]

Each entry in the hash-table (each "slot") is called a tuple and it holds a key and a value.
Consider the following generic implementation of a tuple during your implementation.

template<typename K, typename V>
struct Tuple {
    K key;
    V value;
};

Note that one hash-function may produce the same index for different keys, a so called collision.
Your implementation must be able to handle these collisions. There are many ways to do this, but in your implementation, each type must provide an "equals" function for comparing keys and each tuple must be extended so that it can store multiple keys and values. The way to do this will be left as an exercise for you.

In summary, here's a short class definition to be implemented:

template<typename K, typename V>
class Map {
public:
  // return true if the provided keys are equal
  using EqualsFunction = std::function<bool(const K &, const K &)>;

  // return the hash value for a provided key
  using HashFunction = std::function<int(const K &)>;

  Map(EqualsFunction equals, HashFunction hash);
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

  // ...

private:
  // TODO
};

Please remember to test your implementation, by writing some unit tests for it.
You do not need a framework for this, you can do so using <cassert>.

Once you're done, please answer the following questions:
How does your implementation differ from the C++'s implementation of std::map and std::unordered_map? What are the differences between all of them?
How is STL able to handle custom types without an EqualsFunction as in your implementation? What about HashFunction?
What strategies are there for handling key collision? How do they compare?
How does the size of the hash-table and/or quality of the hash-function influence key collision and performance?
Is an hash-table faster than a balanced binary search tree? Why? In which situations would you prefer a balanced binary search tree over a hash-table?
In a non-balanced binary search tree, what happens if we add sorted data to it?

Good luck!
Let me know if you have any questions.

Please take your time, this exercise is not trivial and will require a moderate amount of research.

Best regards,
