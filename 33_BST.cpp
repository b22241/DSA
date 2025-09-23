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



