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
        HashNode(string word) {
            key = word;
            value = 1;
            next = nullptr;
        }
    };

private:
    // HashMap with 100 spots in the list
    HashNode** table = new HashNode* [100];

    // hash function that returns powers of 31 with ASCII 
    unsigned int hashFunction(string key) {
        unsigned int hashValue = 0;
        for (int i = key.size() - 1; i >= 0; i--)
            hashValue += key[i] * pow(31, i);
        return hashValue % 100;
    }

    // insert hash node into hash map
    void insertHashNode(string word) {
        int index = hashFunction(word);
        bool found = false;

        if (table[index] != nullptr) {
            HashNode* current = table[index];
            while (current != nullptr) {
                if (current->key == word) {
                    current->value++;
                    found = true;
                    break;
                }
            }
        }
        
        if (!found) {
            HashNode* node = new HashNode(word);
            node->next = table[index];
            table[index] = node;
        }
    }

public:
    // default constructor
    HashMap() { 
        string lyrics = "";
    }

    // constructor
    HashMap(string lyrics) {
        for (int i = 0; i < 100; i++) {
            table[i] = nullptr;
        }

        // replace all punctuation with spaces
        for (auto& c : lyrics) {
            if (std::ispunct(c)) {
                c = ' ';
            }
        }

        istringstream stream(lyrics);
        string word;
        while (stream >> word) {
            // make word lowercase
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            insertHashNode(word);
        }
    }

    // destrcutor
    ~HashMap() { }

    // return word frequency
    int getWordFrequency(string word) {
        int index = hashFunction(word);
        bool found = false;

        HashNode* current = table[index];
        while (current != nullptr) {
            if (current->key == word) {
                found = true;
                return current->value;
            }
        }

        if (!false)
            return -1;
    }

    void clear() {
        // delete each node in the table
        for (int i = 0; i < 100; i++) {
            HashNode* current = table[i];
            while (current != nullptr) {
                HashNode* temp = current;
                current = current->next;
                delete temp;
            }
        }

        // delete the table
        delete[] table;
    }
};
