#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int x): data(x), left(nullptr), right(nullptr) {}
};


bool isBSTUtil(Node* root, long long &prev) {
    if (!root) return true;
    if (!isBSTUtil(root->left, prev)) return false;
    if (root->data <= prev) return false;
    prev = root->data;
    return isBSTUtil(root->right, prev);
}

bool isBST(Node* root) {
    long long prev = LLONG_MIN;
    return isBSTUtil(root, prev);
}

int main() {
    
    Node* root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(6);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);

    cout << "Tree1 is " << (isBST(root1) ? "BST" : "Not BST") << "\n";


    Node* root2 = new Node(4);
    root2->left = new Node(5); 
    root2->right = new Node(6);
    cout << "Tree2 is " << (isBST(root2) ? "BST" : "Not BST") << "\n";

    return 0;
}
