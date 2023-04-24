#pragma once
#include <iostream>
#include <list>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

class HashMap {
    // hash node nested struct
    struct HashNode { 
        string key;
        int value;
        HashNode* next;

        // constructor for hash node
        HashNode(string word){
            word = key;
            value = 1;
            next = nullptr;
        }
    };

private:
    // HashMap with 1000 spots in the list
    list<HashNode*> table[1000];

    // hash function that returns powers of 31 with ASCII 
    unsigned int hashFunction(string key) {
        unsigned int hashValue = 0;
        for (int i = key.size() - 1; i >= 0; i--)
            hashValue += key[i] * pow(31,i);
        return hashValue % 1000;
    }

    // insert hash node into hash map
    HashMap insertHashNode(string word) {
        int index = hashFunction(word);
        bool found = false;

        // iterate over each element in list at the index
        // seperate chaining method
        for (auto& node : table[index]) {
            // increase the value of the word if found
            if (node->key == word) {
                node->value++;
                found = true;
                break;
            }
        }

        // add node to hash map if it does not exist yet
        if (!found) {
            HashNode* node = new HashNode(word);
            table[index].push_back(node);
        }
    }

public:
    // constructor
    HashMap(string lyrics) {
        istringstream stream(lyrics);
        string word;
        while (stream >> word) {
            // make word lowercase
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            insertHashNode(word);
        }
    }

    // destrcutor
    ~HashMap() {
        // loop through table and iterate through each bucket list
        for (int i = 0; i < 1000; i++) {
            for (auto& node : table[i]) {
                delete node;
            }
        }
    }
};
