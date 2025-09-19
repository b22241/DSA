#include <iostream>
#include <queue>
#include<algorithm>
#include<climits>
#include<stack>
#include <unordered_map>
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

static int idx = -1;
Node* buildtree(vector<int> &preOrder) {
    idx++;
    if (preOrder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preOrder[idx]);
    root->left = buildtree(preOrder);
    root->right = buildtree(preOrder);
    return root;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//transversal of tree in levels
void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 0) {
        Node* curr = q.front();
        q.pop();
        if (curr == NULL) {
            if (!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
             }
            }
            cout << curr->data << " ";
            if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }

    cout << endl;
}

//height of a tree
int max_height(Node* root){
    if (root == NULL) {
        return 0;
    }   
    int left_ht = max_height(root->left);
    int right_ht = max_height(root->right);
    return 1 + max(left_ht, right_ht);
}

//number of nodes in a tree
int nodes(Node*root){
    if(root==NULL){
        return 0;
    }
    int left=nodes(root->left);
    int right=nodes(root->right);
    return left+right+1;
}

//sum of nodes in a tree
int nodes_sum(Node*root){
    int sum=0;
    if(root==NULL){
        return 0;
    }
    int left_sum=nodes_sum(root->left);
    int right_sum=nodes_sum(root->right);
    return left_sum+right_sum+root->data;
}

//diameter of tree
int ans = INT_MIN;
int diameter(Node* root) {
        if(!root) return 0;
        int left = diameter(root->left);
        int right = diameter(root->right);
        ans = max(left+right, ans);
        return max(left, right) + 1;
}

//top view of a tree
unordered_map<int,Node*> m;
void top_view(Node* root,int count) {
    if (root == NULL) return;
    if (m.find(count) == m.end()) {
        m[count] = root;
    }
    top_view(root->left, count - 1);
    top_view(root->right, count + 1);
    
}

//transversal of kth level in tree
void kthlevel(Node* root,int k) {
    if(root==NULL){
        return;
    }
    if(k==1){
    cout<<root->data<<" ";
    return;
  }
  kthlevel(root->left,k-1);
  kthlevel(root->right,k-1);
}

// //transform to sum tree
// int sum_tree(Node* root){
//     if(root==NULL){
//         return 0;
//     }
//     return root->data= root->data+sum_tree(root->left)+sum_tree(root->right);
// }

// //flatten binary tree to array
// // void binary_array(Node* root, vector<int>& result) {
// //     if (root == NULL) {
// //         return;
// //     }
// //     else{
// //         result.push_back(root->data);               // Visit root
// //     }
// //     binary_linked(root->left, result);          // Traverse left
// //     binary_linked(root->right, result);         // Traverse right
// // }


// //flatten binary tree to linked list 
// void binary_linked(Node* root,vector<int>& result){
//     Node* nextRight;
//      if (root == NULL) {
//         return;
//      }
//     result.push_back(root->data);
//     binary_linked(root->right,result);    
//     binary_linked(root->left,result);          // Traverse left
//     root->left==NULL;
//     root->right==nextRight;
//     nextRight==root;
// }

// // Driver code
int main() {
    // Sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);
    //preorder(root);
    //levelOrder(root);
    //cout<<max_height(root);
    //cout<<nodes(root);
    //cout<<nodes_sum(root);
    //cout<<diameter(root);
    // top_view(root, 0);
    // for (int hd = -100; hd <= 100; hd++) {
    //     if (m.find(hd) != m.end()) {
    //         cout << m[hd]->data << " ";
    //     }
    // }
    //kthlevel(root,3);
//     sum_tree(root); 
//   vector<int> result;
//     binary_linked(root, result);

//     for (int x : result) {
//         cout << x << " ";
//     }
//  vector<int> result;
//  binary_linked(root, result);
// for(int x:result){
//     cout<<x<<" ";
// }
return 0;
}



