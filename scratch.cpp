#include <iostream>

#include "Hashmap.h"

using std::cout, std::endl;

int main() {
    Hashmap map;
    // write your test code here

    map.insert("cat", 7);
    map.insert("cartrage", 46);
    map.insert("life", 44);
    map.insert("The Universe", 43);
    map.insert("cat", 42);
    map.insert("car", 42);
    map.insert("dog", 42);
    map.insert("bat", 42);
    map.insert("bear", 42);
    map.insert("lion", 42);
    map.print();
    map.insert("sep", 42);
    map.insert("Everything and your dog", 42);
    map.insert("Everything is a big thing", 42);
    map.insert("Everything needs to go", 42);
    map.insert("All you can eat", 42);

    cout << map.contains("Cat") << endl;
    cout << map.contains("cat") << endl;
    cout << map.contains("counter") << endl;
    cout << map.get("life") << endl;
    cout << map["life"] << endl;
    map.print();

    int temp = map["deer"];
    temp = 7;

    map["deers"] = 7;
    map["deers"] = 9;

    map.print();


    cout << "Goodbye World!" << endl;
    return 0;
}
