#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool isBST(Node* root, Node* min = NULL, Node* max = NULL) {
    if (root == NULL) {
        return true;
    }

    // Check if the current node's value is within the range defined by min and max
    if (min != NULL && root->data <= min->data) {
        return false;
    }
    if (max != NULL && root->data >= max->data) {
        return false;
    }

    // Recursively check the left and right subtrees with updated min and max
    return isBST(root->left, min, root) && isBST(root->right, root, max);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);

    root->left->left = new Node(1);
    root->left->right = new Node(3);

    root->right->left = new Node(5);
    root->right->right = new Node(7);

    if (isBST(root, NULL, NULL)) {
        cout << "Valid BST" << endl;
    } else {
        cout << "Invalid BST" << endl;
    }

    return 0;
}
