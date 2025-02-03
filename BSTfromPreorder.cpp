#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* constructBST(int preorder[], int* preorderIdx, int key, int min, int max, int n) {
    // Base case
    if (*preorderIdx >= n) {
        return NULL;
    }
    
    Node* root = NULL;
    
    // If key is within the range, then only it can be the root of the subtree
    if (key > min && key < max) {
        root = new Node(key);
        *preorderIdx += 1;

        // Construct the left subtree
        if (*preorderIdx < n) {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }

        // Construct the right subtree
        if (*preorderIdx < n) {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }

    return root;
}

void printPreorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int preorder[] = {10, 2, 1, 13, 11};
    int n = sizeof(preorder) / sizeof(preorder[0]);
    int preorderIdx = 0;
    
    Node* root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    printPreorder(root);
    
    return 0;
}
