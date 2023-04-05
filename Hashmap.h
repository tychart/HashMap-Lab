#pragma once

#include <string>

#include "HashmapInterface.h"

class Hashmap : public HashmapInterface {
private:
    // put any private data members or methods here

public:
    Hashmap() {
        // implement your constructor here
    }

    ~Hashmap() {
        // implement your destructor here
    }

    void insert(std::string key, int value) {
        // implement insert here
    }

    bool contains(const std::string &key) const {
        // implement contains here
    }

    int get(const std::string &key) const {
        // implement get here
    }

    int &operator[](std::string key) {
        // implement operator[] here
    }

    bool remove(const std::string &key) {
        // implement remove here
    }

    void clear() {
        // implement clear here
    }

    std::string toString() const {
        // implement toString here
    }

    int size() const {
        // implement size here
    }
};
