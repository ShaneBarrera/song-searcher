//
// Created by Alex on 4/19/23.
//

#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
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
    Node* root;
    Node* HelperInsertBSTRecursive(Node* helpRoot, string& word);
    Node* HelperGetNode(Node* helpRoot, const string& word);
    void FixRB(Node* node);
public:
    TreeMap(string lyrics = "This is a sample lyric string");
    // need right rotate, left rotate, reverse colors
    void RightRotate(Node* node);
    void LeftRotate(Node* node);
    void Recolor(Node* node);
    //insert function
    void Insert(string& word);
    //search function?
    int GetNumUses(const string& word);
    //extra functions
    Node* GetRoot();
    void PrintInorder(Node* helpRoot);
};
