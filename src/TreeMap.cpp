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

    root = HelperInsertBSTRecursive(root, word);

    //find newnode
    Node* node = HelperGetNode(root, word);

    //if not a new node, end here
    if (node == nullptr) {
        return;
    }

    FixRB(node);
}

void TreeMap::FixRB(TreeMap::Node *node) {
    if (node == root){
        return;
    }
    else if (node->parent->black == true)
    {
        return;
    }
    else if (node->parent->black == false)
    {
        //check whether node's uncle is black or red
        Node* uncle = nullptr;
        if (node->parent->parent != nullptr && node->parent == node->parent->parent->left){
            uncle = node->parent->parent->right;
        }
        else if (node->parent->parent != nullptr && node->parent == node->parent->parent->right){
            uncle = node->parent->parent->left;
        }

        if (uncle != nullptr && uncle->black == false)
        {
            //flip P,U, and G
            Recolor(node->parent);
            Recolor(uncle);
            if (node->parent->parent != root) {
                Recolor(node->parent->parent);
            }
        }
        else if (uncle == nullptr || uncle->black == true)
        {
            //if p is right child of g and k is right child of p
            if (node->parent->parent != nullptr && node->parent == node->parent->parent->right && node == node->parent->right)
            {
                //left rotate g
                Node* gp = node->parent->parent;
//                gp = LeftRotate(gp);
                LeftRotate(gp);
                Node* s = gp;
                Recolor(s);
                if (node->parent->parent != nullptr && node->parent->parent != root) {
                    Recolor(node->parent->parent);
                }            }
            // p is right of g and k is left of p
            else if (node->parent->parent != nullptr && node->parent == node->parent->parent->right && node == node->parent->left)
            {
                Node* parent = node->parent;
//                parent = RightRotate(parent);
                RightRotate(parent);

                if (node->parent->parent != nullptr) {
                    Node *gp = node->parent->parent;
//                gp = LeftRotate(gp);
                    LeftRotate(gp);
                    Node *s = gp;
                    Recolor(s);
                    if (node->parent->parent != nullptr && node->parent->parent != root) {
                        Recolor(node->parent->parent);
                    }
                }
            }
            //symmetric cases for flipped right and left
            //if p is left child of g and k is left child of p
            if (node->parent->parent != nullptr && node->parent == node->parent->parent->left && node == node->parent->left)
            {
                //left rotate g
                Node* gp = node->parent->parent;
                RightRotate(gp);
//                gp = RightRotate(gp);
                Node* s = gp;
                Recolor(s);
                if (node->parent->parent != nullptr && node->parent->parent != root) {
                    Recolor(node->parent->parent);
                }            }
                // p is left of g and k is right of p
            else if (node->parent->parent != nullptr && node->parent == node->parent->parent->left && node == node->parent->right)
            {
                Node* parent = node->parent;
                LeftRotate(parent);
//                parent = LeftRotate(parent);

                if (node->parent->parent != nullptr) {
                    Node *gp = node->parent->parent;
                    RightRotate(gp);
//                gp = RightRotate(gp);
                    Node *s = gp;
                    Recolor(s);
                    if (node->parent->parent != nullptr && node->parent->parent != root) {
                        Recolor(node->parent->parent);
                    }
                }
            }
        }
    }
}

TreeMap::Node *TreeMap::HelperInsertBSTRecursive(Node* helpRoot, string& word) {
    if (helpRoot == nullptr)
    {
        return new Node(word);
    }
        //if it is found
    else if (word.compare(helpRoot->word) == 0)
    {
        helpRoot->numUses++;
    }
//    else if (word < helpRoot->word) //use string compare
    else if (word.compare(helpRoot->word) < 0) //use string compare
    {
        helpRoot->left = HelperInsertBSTRecursive(helpRoot->left, word);
        helpRoot->left->parent = helpRoot;
    }
    else
    {
        helpRoot->right = HelperInsertBSTRecursive(helpRoot->right, word);
        helpRoot->right->parent = helpRoot;
    }

    return helpRoot;
}

int TreeMap::GetNumUses(const std::string &word) {
    Node* foundNode = HelperGetNode(root, word);
    return foundNode->numUses;
}

TreeMap::Node* TreeMap::HelperGetNode(TreeMap::Node *helpRoot, const std::string &word) {
    if (helpRoot == nullptr || helpRoot->word == word)
    {
        return helpRoot;
    }
    else if (word.compare(helpRoot->word) > 0)
    {
        return HelperGetNode(helpRoot->right, word);
    }
    else
    {
        return HelperGetNode(helpRoot->left, word);
    }
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

void TreeMap::RightRotate(TreeMap::Node *node) {
    Node* y = node->left;
    node->left = y->right;
    if (y->right != nullptr){
        y->right = node;
    }
    y->parent = node->parent;
    if (node->parent == nullptr)
    {
        root = y;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = y;
    }
    else
    {
        node->parent->right = y;
    }
    y->right = node;
    node->parent = y;
}

void TreeMap::LeftRotate(TreeMap::Node *node) {
    Node* y = node->right;
    node->right = y->left;
    if (y->left != nullptr){
        y->left = node;
    }
    y->parent = node->parent;
    if (node->parent == nullptr)
    {
        root = y;
    }
    else if (node == node->parent->right)
    {
        node->parent->right = y;
    }
    else
    {
        node->parent->left = y;
    }
    y->left = node;
    node->parent = y;
}

void TreeMap::Recolor(TreeMap::Node *node) {
    node->black = !node->black;
}
