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

    ~Hashmap() override {
        // implement your destructor here
    }

    void insert(std::string key, int value) override {
        // implement insert here
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

    std::string toString() const override {
        // implement toString here
    }

    int size() const override {
        // implement size here
    }
};
