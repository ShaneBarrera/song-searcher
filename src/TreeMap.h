#pragma once
#include <string>
#include <iostream>
using namespace std;

class TreeMap {
    
    struct Node {
        string word;
        int numUses;
        bool black; // true means black, false means red
        Node* parent; //maybe? or just track the parent on BST insert of insertion maybe?
        Node* left;
        Node* right;
        Node(string& x) : word(x), numUses(1), black(false), parent(nullptr), left(nullptr), right(nullptr) {};
    };

public:
    ///constructor should use insert a bunch? like go through lyric string and insert each one?
    TreeMap();
    TreeMap(string& lyrics);
    // need right rotate, left rotate, reverse colors
    Node* RightRotate(Node* parent);
    Node* LeftRotate(Node* parent);
    void Recolor(Node* node);
    //insert function
    void Insert(string& word); /// will I already know numUses, or should it just increase on a hit for insertion? leaning toward second
    //search function?
};

