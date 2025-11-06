#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Correct insert function for BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to build BST from array
Node* buildBST(vector<int> arr) {
    Node* root = nullptr;
    for (int val : arr) {
        root = insert(root, val);
    }
    return root;
}


void inorder(Node* root,int &index,int &ans,int k){
    if(root==NULL)return;

    inorder(root->left,index,ans,k);
    index++;
    if(index==k){
        ans=root->data;
        exit;
    } 
    inorder(root->right,index,ans,k);
}
int kthSmallest(Node* root, int k) {
    // Write your code here.
    int ans=-1;
    int index=0;
    inorder(root,index,ans,k);
    return ans;

}


Node*  help(Node* root,int key){
    if(root==NULL) return NULL;
    if(root->data==key) return root;

    Node* left=help(root->left,key);
    Node* right=help(root->right,key);
}

Node* find(Node* root,int key){
    if(root==NULL) return NULL;
    if(root->data==key) return root;

    Node* left = find(root->left,key);
    if(left) return left;
    return find(root->right,key);
}

pair<int, int> predecessorSuccessor(Node *root, int key){
    pair<int,int> p={-1,-1};
    
    Node* val = find(root,key);
    if(val == NULL) return p;

    Node* temp;

    // Predecessor
    if(val->left){
        temp = val->left;
        while(temp->right){
            temp = temp->right;
        }
        p.first = temp->data;
    }

    // Successor
    if(val->right){
        temp = val->right;
        while(temp->left){
            temp = temp->left;
        }
        p.second = temp->data;
    }

    return p;
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildBST(arr);
    // int ans=kthSmallest(root,3);
    // cout<<ans;

    int key=5;
    pair<int, int>p= predecessorSuccessor(root,key);
    cout<<p.first<<p.second;
}