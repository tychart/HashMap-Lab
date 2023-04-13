#pragma once

#include <string>
#include <vector>
#include <list>

#include "HashmapInterface.h"
#include "Pair.h"

using std::vector, std::list, std::string, std::cout, std::endl;

class Hashmap : public HashmapInterface {
private:
    size_t bucketAmmount = INITIAL_BUCKETS;
    size_t currSize = 0;
    vector<list<Pair>> mainMap;

    // https://stackoverflow.com/questions/98153/whats-the-best-hashing-algorithm-to-use-on-a-stl-string-when-using-hash-map
    size_t getHashedPos(const string &str, size_t seed = 0) const {
        const char* s = str.c_str();
        size_t hash = seed;
        while (*s) {
            hash = hash * 101  +  *s++;
        }
//        cout << "Returning: " << hash % currSize << endl;
        return hash % bucketAmmount;
    }

    void maybeGrow() {
        int temp = bucketAmmount * MAX_LOAD_FACTOR;
        if (currSize > bucketAmmount * MAX_LOAD_FACTOR) {
            grow();
        }
    }

    void grow() {
        bucketAmmount *= GROW_FACTOR;
        vector<list<Pair>> tempMainMap = vector<list<Pair>>(bucketAmmount);

        for (auto i : mainMap) {
            for (auto &j: i) {
                size_t pos = getHashedPos(j.key);
                tempMainMap[pos].push_back(Pair(j.key, j.val));
            }
        }
        mainMap = tempMainMap;

    }



public:
    Hashmap() {
        // implement your constructor here
        mainMap = vector<list<Pair>>(10);

    }

    ~Hashmap() override {
        // implement your destructor here
//        clear();
    }



    void insert(std::string key, int value) override {
        maybeGrow();
        _insert(mainMap, key, value);
    }

    void _insert(vector<list<Pair>> &currMap, string key, int value) {

        size_t pos = getHashedPos(key);
//        auto it = currMap[pos].begin();
        for (auto &i : currMap[pos]) {
            if (i.key == key) {
                i.key = key;
                i.val = value;
                return;
            }
        }
        currMap[pos].push_back(Pair(key, value));
        currSize++;
    }

    bool contains(const std::string &key) const override {
        size_t pos = getHashedPos(key);
//        auto it = mainMap[pos].begin();
        for (auto &i : mainMap[pos]) {
            if (i.key == key) {
                return true;
            }
        }
        return false;
    }

    int get(const std::string &key) const override {

        size_t pos = getHashedPos(key);
//        auto it = mainMap[pos].begin();
        for (auto &i : mainMap[pos]) {
            if (i.key == key) {
                return i.val;
            }
        }
        throw std::invalid_argument("Invalid syntax.");

    }

    int &operator[](const std::string& key) override {
        size_t pos = getHashedPos(key);
//        auto it = mainMap[pos].begin();
        for (auto &i : mainMap[pos]) {
            if (i.key == key) {
                return i.val;
            }
        }
        mainMap[pos].push_back(Pair(key, 0));
        return mainMap[pos].back().val;
    }

    bool remove(const std::string &key) override {
        size_t pos = getHashedPos(key);
        list<Pair>::iterator it = mainMap[pos].begin();
        while (it != mainMap[pos].end()) {
            if (it->key == key) {
                mainMap[pos].erase(it);
                return true;
            }
            it++;
        }
        return false;
    }

    void clear() override {
        // implement clear here
    }
    
    int numBuckets() const override {
        return bucketAmmount;
    }

    int size() const override {
        return currSize;
    }

    void print() {
        int counter = 0;
        for (auto i : mainMap) {
            cout << "Slot " << counter << ": ";
            for (auto &j: i) {
               cout << "[" << j.key << ", " << j.val << "]";
            }
            cout << endl;
            counter++;
        }
    }

};

