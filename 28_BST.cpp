#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

int idx = -1;
Node* buildTree(vector<int> preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);  // LEFT subtree
    root->right = buildTree(preorder); // RIGHT subtree
    return root;
}

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//height of tree
// int height(Node* root){
//     if(root==0){
//         return 0;
//     }
//     int left_height=height(root->left);
//     int right_height=height(root->right);
//     return max(left_height,right_height)+1;
// }

//number of nodes
// int count(Node* root){
//     if(root==0){
//         return 0;
//     }
//     int left=count(root->left);
//     int right=count(root->right);
//     return left+right+1;
// }

//sum of nodes
// int sum(Node* root){
//     if(root==0){
//         return 0;
//     }
//     int left_sum=sum(root->left);
//     int right_sum=sum(root->right);
//     return left_sum+right_sum+root->data;
// }

//identical trees
// bool isidentical(Node* root1, Node* root2) {
//     // Both are NULL
//     if (root1 == NULL || root2 == NULL)
//         return root1==root2;
//     // Recursively check left and right subtrees
//     int isleftsame=isidentical(root1->left,root2->left);
//     int isrightsame=isidentical(root1->right,root2->right);
//     return isrightsame && isleftsame && root1->data==root2->data;
// }

// //find out subtree of another tree or not
// bool is_subtree(Node* root, Node* subroot) {
//     if (root == NULL|| subroot==NULL){
//         return root==subroot;
//     if(root->data==subroot->data && isidentical(root,subroot)){
//         return true;
//     }
//     else{
//         return         
//            is_subtree(root->left,subroot) || is_subtree(root->right,subroot);
//     }
// }
// }

// Top view function
//ordered map ->O(logn)
//unordered map->O(1)
// O(nlogn)
void topView(Node* root) {
    if (root == NULL) return;

    // Queue of pairs: <Node*, horizontal_distance>
    queue<pair<Node*, int>> q;
    map<int, int> m; // <horizontal_distance, node->data>- 

    q.push({root, 0});

    while (!q.empty()) {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        // Store the node data if this horizontal distance is seen first time
        if (m.find(currHD) == m.end()) {
            m[currHD] = curr->data;
        }

        // Add left and right children to queue with updated HD
        if (curr->left != NULL) {
            q.push({curr->left, currHD - 1});
        }
        if (curr->right != NULL) {
            q.push({curr->right, currHD + 1});
        }
    }
 for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

//kth level of a tree
void kth_level(Node* root, int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    kth_level(root->left,k-1);
    kth_level(root->right,k-1);
}

int sum_tree(Node* root) {
    if (root == NULL) return 0; 
    int leftSum = sum_tree(root->left);
    int rightSum = sum_tree(root->right);
    root->data = root->data + leftSum + rightSum;
    return root->data;
}


int main() {
vector<int> preorder1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    //idx = -1;  // Reset index before each build
    Node* root = buildTree(preorder1);
    // vector<int> preorder2 = {3,4,-1,-1,5,-1,-1};
    // idx = -1;  // Reset index before each build
    // Node* subroot = buildTree(preorder2);

    // vector<int> preorder2 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    // idx = -1;
    // Node* root2 = buildTree(preorder2);
    // //cout<<height(root);
    // //cout<<count(root);
    // //cout<<sum(root);
    // if(isidentical(root1,root2)==1){
    //     cout<<"Both Trees are identical";
    // }
    // else{
    //     cout<<"Trees are not identical";
    // }

    // if(is_subtree(root,subroot)==1){
    //     cout<<"Both Trees are identical";
    // }
    // else{ 
    //     cout<<"Trees are not identical";
    // }
    //topView(root); 
    //kth_level(root,2);
    // preorder(root);
    // cout<<endl;
    // sum_tree(root);
    // preorder(root);
    
    
}