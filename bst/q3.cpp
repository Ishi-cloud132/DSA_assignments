
#include <iostream>
#include <vector>
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

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* removeNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->key) root->left = removeNode(root->left, key);
    else if (key > root->key) root->right = removeNode(root->right, key);
    else {
        // found node
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        } else {
            Node* succ = findMin(root->right);
            root->key = succ->key;
            root->right = removeNode(root->right, succ->key);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int vals[] = {50, 30, 20, 40, 70, 60, 80};
    for (int v : vals) root = insert(root, v);

    cout << "Inorder: "; inorder(root); cout << "\n";
    cout << "Max depth: " << maxDepth(root) << "\n";
    cout << "Min depth: " << minDepth(root) << "\n";

    cout << "Delete 20\n"; root = removeNode(root, 20);
    cout << "Inorder: "; inorder(root); cout << "\n";

    cout << "Delete 30\n"; root = removeNode(root, 30);
    cout << "Inorder: "; inorder(root); cout << "\n";

    cout << "Delete 50\n"; root = removeNode(root, 50);
    cout << "Inorder: "; inorder(root); cout << "\n";

    return 0;
}
