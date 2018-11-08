# Lab9-Hashmap

## Briefing: 
Implement your own map using a hash table, like the C++ STL unordered\_map class. The goal is to get your insert, find, and remove functions to have an average runtime of O(1).

## File 1 - Insert and Get (10 pts)
### Insert
* The insert function takes in 2 parameters: string key and int value
* First, use your hash function to figure out which bucket (which index of your buckets array) the key belongs in
* Remember that buckets[hashcode] is a Node pointer that represents the head of your doubly-linked list for that bucket
* Iterate through all of the nodes in the list at buckets[hashcode] to see if the insert key is already in the map
* If you find a node with the input key already in the map, update that node's value to the new input value
* If you do not find a node with the value, create a new node and insert it into the doubly linked list at buckets[hashcode]

### Get
* The get function takes in 1 parameter: string key
* First, use your hash function to figure out which bucket the key belongs in
* Iterate through all of the nodes in the list at buckets[hashcode] to find the node with the matching key
* If you find a node with a matching key, return that node's value
* If you don't find a node with a matching key, throw an invalid\_argument exception (http://www.cplusplus.com/reference/stdexcept/invalid_argument/)

### Size
* You'll also need your size function to return the number of nodes in the map
* Your map class should use a private member variable to keep track of size, make sure to update it when nodes are inserted and removed

## File 2 - Insert and Contains (10 pts)
* The contains function takes in 1 parameter: string key
* Return true if the key is in the map, false otherwise
* Remember to start by using your hash function to figure out which bucket the key would be in if it was in the map

File 2 also performs additional tests on insert to make sure that your code can handle multiple inserts into a single bucket.

## File 3 - The [] operator (15 pts)
* For inserting a new key/value pair, getting value by key, or updating value by key
* The operator [] function returns an int& to allow all of these operations
* First, use your hash function to figure out which bucket the key belongs in
* If you find the node with the matching key in the map, then return that node's value (this will allow the caller to both get and update the value)
* If you do not find the node with the matching key in the map, insert a new node with a value of 0 into the appropriate bucket and return newNode-\>value

File 3 also performs additional tests on insert and get to make sure that insert can be used to overwrite values and that get will throw an invalid\_argument exception when the key isn't in the map. Also tests to make sure that multiple keys can be chained together in a single bucket.

## File 4 - Remove and Clear (20 pts)

## File 5 - Everything Combined (10 pts)

## Valgrind - (15 pts)

## Word Count (toSortedString) - (20 pts)
