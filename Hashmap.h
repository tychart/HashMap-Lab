#pragma once
#include "HashmapInterface.h"
#define BUCKETS 100

using namespace std;

class Hashmap: public HashmapInterface
{
private:
	struct Node {
		string key;
		int value;
		Node* prev;
		Node* next;
	};
	Node* buckets[BUCKETS];
	int mapSize;
	unsigned int hash(string key);
public:
	Hashmap();
	~Hashmap();
	void insert(string key, int value);
	bool contains(string key) const;
	int get(string key) const;
	int& operator [](string key);
	bool remove(string key);
	void clear();
	string toString();
	int size();
};
