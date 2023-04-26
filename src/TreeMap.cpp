//
// Created by Alex on 4/19/23.
//

#include "TreeMap.h"

// O(n log n) where n is number of unique words
TreeMap::TreeMap(string lyrics) {
    root = nullptr;

    // Replace all punctuation with spaces
    //FIXME: breaks up contractions? maybe ignore this, or tell it to ignore single characters?
    for (auto& c : lyrics) {
        if (std::ispunct(c) || !isalpha(c)) {
            c = ' ';
        }
    }

    // insert each word in lyrics
    istringstream stream(lyrics);
    string word;
    while (stream >> word) {
        /// make word lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        Insert(word); //o(logn)
    }
}

//O(log n) because of combination of parts
void TreeMap::Insert(std::string &word) {
    /// use BST insert first
    // traverse to location
    // if I find it, increase numUses
    // else insert word as a new node

    // o(logn) where n is number of nodes/unique words
    root = HelperInsertBSTRecursive(root, word);

    //find newnode o(log n)
    Node* node = HelperGetNode(root, word);

    //if not a new node, end here
    if (node == nullptr) {
        return;
    }

    //o(1)
    FixRB(node);
}

//O(1) (there are a max of two rotations, which is constant)
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

//O(log n)
int TreeMap::GetNumUses(const std::string &word) {
    Node* foundNode = HelperGetNode(root, word);
    if (foundNode == nullptr){
        return 0;
    }

    return foundNode->numUses;
}

//O(log n)
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

//o(1)
TreeMap::Node* TreeMap::GetRoot() {
    return root;
}

//o(n), not used, just for testing
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

//O(1)
void TreeMap::RightRotate(TreeMap::Node *node) {
    if (node->left != nullptr) {
        Node *y = node->left;
        node->left = y->right;
        if (y->right != nullptr) {
            y->right = node;
        }
        y->parent = node->parent;
        if (node->parent == nullptr) {
            root = y;
        } else if (node == node->parent->left) {
            node->parent->left = y;
        } else {
            node->parent->right = y;
        }
        y->right = node;
        node->parent = y;
    }
}

//O(1)
void TreeMap::LeftRotate(TreeMap::Node *node) {
    if (node->right != nullptr) {
        Node *y = node->right;
        node->right = y->left;
        if (y->left != nullptr) {
            y->left = node;
        }
        y->parent = node->parent;
        if (node->parent == nullptr) {
            root = y;
        } else if (node == node->parent->right) {
            node->parent->right = y;
        } else {
            node->parent->left = y;
        }
        y->left = node;
        node->parent = y;
    }
}

//O(1)
void TreeMap::Recolor(TreeMap::Node *node) {
    node->black = !node->black;
}

//destructor
//TreeMap::~TreeMap() {
//    HelperDestruct(root);
//}
//
// Helper function to recursively destroy and delete nodes
void TreeMap::HelperDestruct(TreeMap::Node *helpRoot) {
    if (helpRoot != nullptr)
    {
        if (helpRoot->left != nullptr) {
            HelperDestruct(helpRoot->left);
        }
        if (helpRoot->right != nullptr) {
            HelperDestruct(helpRoot->right);
        }
        delete helpRoot;
    }
}