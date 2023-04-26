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
    // HashMap with 1000 spots in the list
    HashNode* table[1000] = { nullptr };

    // hash function that returns powers of 31 with ASCII 
    unsigned int hashFunction(string key) {
        unsigned int hashValue = 0;
        for (int i = key.size() - 1; i >= 0; i--)
            hashValue += key[i] * pow(31, i);
        return hashValue % 1000;
    }

    // insert hash node into hash map
    void insertHashNode(string word) {
        int index = hashFunction(word);
        bool found = false;
        
        // iterate over each element in list at the index
        HashNode* node = table[index];
        while (node != nullptr) {
            // increase the value of the word if found
            if (node->key == word) {
                node->value++;
                found = true;
                break;
            }
            node = node->next;
        }

        // add node to hash map if it does not exist yet
        if (!found) {
            node = new HashNode(word);
            node->next = table[index];
            table[index] = node;
        }
    }

public:
    // default constructor
    HashMap() { string lyrics = ""; }

    // constructor
    HashMap(string lyrics) {
        // Replace all punctuation with spaces
        //FIXME: breaks up contractions? maybe ignore this, or tell it to ignore single characters?
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
    ~HashMap() {
        // loop through table and iterate through each bucket list
        for (int i = 0; i < 1000; i++) {
            HashNode* node = table[i];
            while (node != nullptr) {
                HashNode* next = node->next;
                delete node;
                node = next;
            }
        }
    }

    // return word frequency
    int getWordFrequency(string word) {
        int index = hashFunction(word);

        // iterate over the linked list at the index
        HashNode* node = table[index];
        while (node != nullptr) {
            // return the value of the word
            if (node->key == word)
                return node->value;
            node = node->next;
        }
        return -1;
    }
};
