#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int calcDiameter(Node* root , int* height){
    if(root==NULL){
        return 0;
    }
    int lh = 0;
    int rh = 0;

    int lDiameter = calcDiameter(root->left,&lh);
    int rDiameter = calcDiameter(root->right,&rh);

    int currDiameter = lh+rh+1;
    *height = max(lh,rh)+1;

    return max(currDiameter,max(lDiameter,rDiameter));
}

int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

    int height = 0;

    cout<<calcDiameter(root,&height)<<endl;
}
