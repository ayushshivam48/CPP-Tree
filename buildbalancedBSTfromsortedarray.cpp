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

Node* sortedArrarToBST(int arr[],int start, int end){

    if(start>end){
        return NULL;
    }

    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);
    
    root->left = sortedArrarToBST(arr,start,mid-1);
    root->right = sortedArrarToBST(arr,mid+1,end);
    return root;
}

void preorderPrint(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main(){
    int arr[]={10,20,30,40,50};
    Node* root=sortedArrarToBST(arr,0,4);
    preorderPrint(root);
    cout<<endl;
}