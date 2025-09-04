#include <iostream>
#include <vector>
#include <cmath>
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

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

//find wheater that key value is there or not in tree
bool search(Node*root,int val){
    if (root == nullptr) return false;
    if(root->data==val){
        return true;
    }
    if(val>root->data){
        return search(root->right,val);
    }
     if(val<root->data){
        return search(root->left,val);
    }
    return false;
}

//find inorder successer of a tree(just after elemet in sorted order)
Node* inorder_successer(Node* root) {
    while(root!=NULL  && root->left!=NULL){
        root=root->left;
    }
    return root;
}

//deleting a node in tree
Node* delete_node(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data > key) {
        root->left = delete_node(root->left, key);
    } else if (root->data < key) {
        root->right = delete_node(root->right, key);
    } else {
        // Node to delete found

        // Case 1: No children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: Two children
        if (root->left != NULL && root->right != NULL) {
            Node* succ = inorder_successer(root->right);
            root->data = succ->data;
            root->right = delete_node(root->right, succ->data);
            return root;
        }

        // Case 3: One child
        Node* child = (root->left != NULL) ? root->left : root->right;
        delete root;
        return child;
    }

    return root;
}

//cheking if given tree is valid or not
bool is_valid_bst(Node* root,Node* min,Node* max) {
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    return is_valid_bst(root->left,min,root) && is_valid_bst(root->right,root,max);
}

bool helper(Node* root){
    is_valid_bst(root,NULL,NULL);
}

// Inorder traversal
vector<int> inorder(Node* root, vector<int>& arr) {
    if (root == nullptr) return arr;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
    return arr;
}

//merge 2 bst to form a single bst
vector<int> buildBST_from2_bst(Node* root1,Node* root2){
    vector<int>arr1,arr2;
    inorder(root1,arr1);
    inorder(root2,arr2);
    vector<int>temp;
    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]>arr2[j]){
            temp.push_back(arr2[j++]);
        } 
        else{
           temp.push_back(arr1[i++]);
        }   
    }
    while(i<arr1.size()){
        temp.push_back(arr1[i++]);
    }
    while(j<arr2.size()){
        temp.push_back(arr2[j++]);
    }
    return temp;
}

//find largest BST in a give bst
Node* largest_bst(Node* root, Node* min, Node* max) {
    if (root == NULL) return NULL;
    Node* ans = NULL;
    if (is_valid_bst(root, min, max)) {
        ans = root;
    }
    Node* leftAns = largest_bst(root->left, min, root);
    Node* rightAns = largest_bst(root->right, root, max);

    // Prefer deeper valid BSTs
    if (leftAns != NULL && (ans == NULL || leftAns->data > ans->data)) {
        ans = leftAns;
    }
    if (rightAns != NULL && (ans == NULL || rightAns->data > ans->data)) {
        ans = rightAns;
    }
    return ans;
}

int max_width(Node* root){
    
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildBST(arr);
    // cout << "Preorder traversal of BST: ";
    preorder(root);

    //cout<<search(root,6);

    //after deleting a node
    // delete_node(root,5);
    // inorder(root);

    //checking for valid bst
    //cout << (helper(root) ? "Valid BST" : "Not a BST") << endl;

    //merging  2 bst to forma  single bst
    // vector<int>arr1={8,2,1,10};
    // vector<int>arr2={5,3,0};
    // Node* root1=buildBST(arr1);
    // Node* root2=buildBST(arr2);
    // vector<int> temp = buildBST_from2_bst(root1, root2);
    // for (int x : temp) {
    //     cout << x << " ";
    // }

    //checking for largest bst
    // Node* largestBSTRoot = largest_bst(root, NULL, NULL);
    // if (largestBSTRoot != NULL) {
    //     cout << "Root of largest BST: " << largestBSTRoot->data << endl;
    // } else {
    //     cout << "No valid BST found" << endl;
    // }
    
}
