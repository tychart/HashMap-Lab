# Hashmap Lab

## Instructions 

Implement your own map using a hash table, like the C++ STL unordered_map class. The goal is to get your insert, find, and remove functions to have an average runtime of O(1).

Implement your hashmap in `Hashmap.h` (you are welcome to write a `Hashmap.cpp` if you prefer). Your hashmap will use keys of type `string` and values of type `int`.

The hash table you build should use chaining. You can use whatever chaining implementation you prefer (build your own linked list, use `list` from the STL, etc). 

You should start your hash table capacity at 10 and double it each time you grow. You should use a load factor of 0.8. Constants for these values are found in `HashmapInterface.h`.

You are responsible for providing your own hash function. You can write your own or copy one from a reputable source (provide proper attribution in a comment). Find something that has the properties we discussed in class: deterministic, efficient, uniform, defined range.

## Testing

The tests used by the autograder are provided to you in `tests.cpp`. You can write your own additional tests in `scratch.cpp`. 

The tests exercise all the methods defined in `HashmapInterface.h`.
