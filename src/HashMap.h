#pragma once
#include <string>
#include <iostream>
#include <list>
using namespace std;

class HashMap {
    struct HashNode {
        string key;
        int value;
        HashNode* next;
        HashNode(string key) {
            this->key = key;
            value = 0;
            next = nullptr;
        }
    };

private:
    list<HashNode> table[100];
    int getHash(string key) {
        int hashValue = 0;
        for (int i = key.size(); i > 0; i--)
            hashValue = hashValue * 31 + key[i];
        return hashValue % 100;
    }

public:
    // constructor
    HashMap(string lyrics) {
        while (lyrics.size() > 0) {
            //if (lyrics.find(" "))
            string word = lyrics.substr(0, (lyrics.find(" ")));

        }
    }

    // destructor
    ~HashMap() {

    }
    
};

// insert hash(key, value);