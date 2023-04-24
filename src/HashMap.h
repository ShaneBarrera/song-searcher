#pragma once
#include <iostream>
#include <list>

using namespace std;

class HashMap {
    struct HashNode { 
        string key;
        int value;
        HashNode* next;
        HashNode(string word){
            word = key;
            value = 1;
            next = nullptr;
        }
    };

private:
    list<HashNode*> table[1000];
    int hashFunction(string key) {
        int hashValue = 0;
        for (int i = key.size(); i > 0; i--)
            hashValue = hashValue * 31 + key[i];
        return hashValue % 1000;
    }

public:
    // constructor
    HashMap(string key) {
        HashNode* node = new HashNode(key);
        int index = hashFunction(key);
        table[index].push_back(node);
    }

    // destrcutor
    ~HashMap() {
        for (int i = 0; i < 1000; i++) {
            for (auto& node : table[i]) {
                delete node;
            }
        }
    }

    HashMap insertHashNode(string word) {
        int index = hashFunction(word);
        for (auto& node : table[index]) {
            if (node->key == word) {
                node->value++;
                return;
            }
        }
        HashNode* node = new HashNode(word);
        table[index].push_back(node);
    }
    
};
