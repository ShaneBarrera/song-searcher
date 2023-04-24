//
// Created by Alex on 4/19/23.
//

#include "TreeMap.h"

TreeMap::TreeMap(const string& lyrics) {
    root = nullptr;
    // insert each word in lyrics
    istringstream stream(lyrics);
    string word;
    while (stream >> word) {
        Insert(word);
    }
}

void TreeMap::Insert(std::string &word) {
    /// make word lowercase
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    /// use BST insert first
    // traverse to location
    // if I find it, increase numUses
    // else insert word as a new node

    //fixme: not sure how to get a pointer to the newly inserted node
    Node* newNode = nullptr;
    root = HelperInsertBSTRecursive(root, word, newNode);

    //if not a new node, end here
    if (newNode == nullptr) {
        return;
    }

    /// then apply RB rules
    while (newNode->parent->black == false)
    {
        cout << "checking RB now" << endl;
    }

    /// pseudocode
//    while k.parent.color == RED
//    if k.parent == k.parent.parent.right
//    u = k.parent.parent.left //uncle
//    if u.color == RED // case 3.1
//    u.color = BLACK
//    k.parent.color = BLACK
//    k.parent.parent.color = RED
//    k = k.parent.parent
//    else if k == k.parent.left // case 3.3.1 and 3.3.2
//    k = k.parent
//    LEFT-ROTATE(T, k)
//    k.parent.color = BLACK
//    k.parent.parent.color = RED
//    RIGHT-ROTATE(T, k.parent.parent)
//    else (same as then clause with “left” and “right” exchanged)
//    T.root.color = BLACK

}

TreeMap::Node *TreeMap::HelperInsertBSTRecursive(Node* helpRoot, string& word, Node* newNodePointer) {
    if (helpRoot == nullptr)
    {
        newNodePointer = new Node(word);
        return newNodePointer;
    }
        //if it is found
    else if (word.compare(helpRoot->word) == 0)
    {
        helpRoot->numUses++;
    }
//    else if (word < helpRoot->word) //use string compare
    else if (word.compare(helpRoot->word) < 0) //use string compare
    {
        helpRoot->left = HelperInsertBSTRecursive(helpRoot->left, word, newNodePointer);
        helpRoot->left->parent = helpRoot;
    }
    else
    {
        helpRoot->right = HelperInsertBSTRecursive(helpRoot->right, word, newNodePointer);
        helpRoot->right->parent = helpRoot;
    }

    return helpRoot;
}

TreeMap::Node* TreeMap::GetRoot() {
    return root;
}

void TreeMap::PrintInorder(Node* helpRoot) {
    if (helpRoot->left != nullptr)
    {
        PrintInorder(helpRoot->left);
    }
    cout << helpRoot->word << ": " << helpRoot->numUses << endl;
    if (helpRoot->right != nullptr)
    {
        PrintInorder(helpRoot->right);
    }
}

TreeMap::Node* TreeMap::RightRotate(TreeMap::Node *parent) {
    Node* temp = nullptr;
    Node* child = parent->left;

    temp = child->right;
    child->right = parent;
    parent->left = temp;

    return child;
}

TreeMap::Node* TreeMap::LeftRotate(TreeMap::Node *parent) {
    Node* temp = nullptr;
    Node* child = parent->right;

    temp = child->left;
    child->left = parent;
    parent->right = temp;

    return child;
}

void TreeMap::Recolor(TreeMap::Node *node) {
    node->black = !node->black;
}
