//
// Created by tychart on 4/12/23.
//

#pragma once

#include <string>

struct Pair {
    std::string key;
    int val;
    Pair(std::string k, int v) {
        key = k;
        val = v;
    }
};