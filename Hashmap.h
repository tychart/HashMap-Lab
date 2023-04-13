#pragma once

#include <string>
#include <vector>
#include <list>
#include "HashmapInterface.h"
using std::vector, std::list, std::string;

class Hashmap : public HashmapInterface {
private:
    // put any private data members or methods here

    size_t currSize = INITIAL_BUCKETS;
    vector<list<int>> mainMap;

    // https://stackoverflow.com/questions/98153/whats-the-best-hashing-algorithm-to-use-on-a-stl-string-when-using-hash-map
    size_t getHashedPos(const string &str, size_t seed = 0) const {
        const char* s = str.c_str();
        size_t hash = seed;
        while (*s) {
            hash = hash * 101  +  *s++;
        }
        return hash % currSize;
    }



public:
    Hashmap() {
        // implement your constructor here
        mainMap = vector<list<int>>(10);

    }

    ~Hashmap() override {
        // implement your destructor here
        clear();
    }

    void insert(std::string key, int value) override {
        size_t pos = getHashedPos(key);
        auto it = mainMap[pos].begin();
        for (auto const &i : mainMap[pos]) {
            if (i == value) {
                return; //
            }
        }
        mainMap[pos].push_back(value);

    }

    bool contains(const std::string &key) const override {
        // implement contains here
    }

    int get(const std::string &key) const override {
        // implement get here
    }

    int &operator[](const std::string& key) override {
        // implement operator[] here
    }

    bool remove(const std::string &key) override {
        // implement remove here
    }

    void clear() override {
        // implement clear here
    }
    
    int numBuckets() const override {
        // implement numBuckets here
    }

    int size() const override {
        // implement size here
    }
};

