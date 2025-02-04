#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

struct Info{
    int size;   // Size of the tree
    int max;    // Maximum value in the subtree
    int min;    // Minimum value in the subtree
    int ans;    // Size of the largest BST found
    bool isBST; // Is the current subtree a BST
};

Info largestBSTinBT(Node* root) {
    if (root == NULL) {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL) {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = 1 + leftInfo.size + rightInfo.size;

    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data) {
        curr.min = min(leftInfo.min, root->data);
        curr.max = max(rightInfo.max, root->data);
        curr.ans = curr.size;
        curr.isBST = true;
    } else {
        curr.ans = max(leftInfo.ans, rightInfo.ans);
        curr.isBST = false;
    }

    return curr;
}

int main() {
    Node* root1 = new Node(15);
    root1->left = new Node(20);
    root1->right = new Node(30);

    root1->left->left = new Node(5);

    cout << "Largest BST in BT: " << largestBSTinBT(root1).ans << endl;
    return 0;
}
