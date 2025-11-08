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

class info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node* root, int &ans){
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;

    currNode.isBST = left.isBST && right.isBST && 
                     (root->data > left.maxi) && 
                     (root->data < right.mini);

    currNode.mini = min(root->data, left.mini);
    currNode.maxi = max(root->data, right.maxi);

    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }

    return currNode; 
}

int largestBST(Node * root){
    int maxSize = 0;
    solve(root, maxSize);
    return maxSize;
}



int main() {
Node* root = new Node(50);
root->left = new Node(30);
root->right = new Node(60);

root->left->left = new Node(5);
root->left->right = new Node(20);

root->right->left = new Node(45);
root->right->right = new Node(70);

root->right->right->left = new Node(65);
root->right->right->right = new Node(80);

    int maxSie=largestBST(root);
    cout<<maxSie;
}