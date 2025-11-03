
#include <iostream>
#include<vector>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int x): key(x), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}


Node* searchRec(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return searchRec(root->left, key);
    return searchRec(root->right, key);
}


Node* searchIter(Node* root, int key) {
    while (root) {
        if (root->key == key) return root;
        if (key < root->key) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

Node* findMin(Node* root) {  
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}


Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}


Node* inorderSuccessor(Node* root, Node* node) {
    if (!root || !node) return nullptr;
   
    if (node->right) return findMin(node->right);
   
    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (node->key < cur->key) { succ = cur; cur = cur->left; }
        else if (node->key > cur->key) cur = cur->right;
        else break;
    }
    return succ;
}


Node* inorderPredecessor(Node* root, Node* node) {
    if (!root || !node) return nullptr;
    if (node->left) return findMax(node->left);
    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (node->key > cur->key) { pred = cur; cur = cur->right; }
        else if (node->key < cur->key) cur = cur->left;
        else break;
    }
    return pred;
}

int main() {
    Node* root = nullptr;
    int vals[] = {20, 10, 30, 5, 15, 25, 35};
    for (int v : vals) root = insert(root, v);

    int key = 10;
    cout << "Search Rec("<<key<<"): " << (searchRec(root,key)? "Found":"Not Found") << "\n";
    cout << "Search Iter("<<key<<"): " << (searchIter(root,key)? "Found":"Not Found") << "\n";

    cout << "Min: " << findMin(root)->key << "\n";
    cout << "Max: " << findMax(root)->key << "\n";

    Node* node = searchIter(root, 20);
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);
    cout << "Node: " << node->key << "\n";
    cout << "Inorder Successor: " << (succ ? to_string(succ->key) : string("NULL")) << "\n";
    cout << "Inorder Predecessor: " << (pred ? to_string(pred->key) : string("NULL")) << "\n";

    return 0;
}
