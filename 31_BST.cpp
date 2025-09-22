#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;  
        left = right = NULL;
    }
};

static int idx = -1;
// construct binary tree from given preorder sequence
Node* builtTree(vector<int>& arr) {
    idx++;  
    if (arr[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(arr[idx]);
    root->left = builtTree(arr);
    root->right = builtTree(arr);
    return root;
}

void preOrder(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root==NULL) return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL) return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root) {
    if (root == NULL) return; 
    queue<Node*> q;
    q.push(root);
    q.push(NULL);  // ✅ marker for end of first level

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << endl;  // end of a level
            if (!q.empty()) {
                q.push(NULL); // add marker for next level
            }
        } else {
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

//height of tree
int height(Node* root){
    if(root==0){
        return 0;
    }
    int left_height=height(root->left);
    int right_height=height(root->right);
    return max(left_height,right_height)+1;
}

//count number of nodes
int nodes(Node* root){
    if (root==NULL) return 0;

    int leftNode=nodes(root->left);
    int rightNode=nodes(root->right);
    return leftNode+rightNode+1;
}

//sum of nodes
int sum(Node* root){
    if (root==NULL) return 0;

    int leftSum=sum(root->left);
    int rightSum=sum(root->right);
    return leftSum+rightSum+root->data;
}

//check if 2 trees are identical or not
bool isSameTree(Node* p, Node* q) {
        if(p && !q || q && !p) return false;
        if(p==NULL && q==NULL) return true;
        if(p->data!=q->data) return false;

        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        return left && right;
}

//diameter of a tree
int ans = INT_MIN;
int diameter(Node* root) {
        if(!root) return 0;
        int left = diameter(root->left);
        int right = diameter(root->right);
        ans = max(left+right, ans);
        return max(left, right) + 1;
}

//top view of tree
void topView(Node* root) {
    if (root == NULL) return; 
    map<int,int>m;
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while (!q.empty()) {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        if(m.find(currHD)==m.end()){           //it's time complexity is O(logn), map stores values in sorted order
            m[currHD]=curr->data;;
        }
        if (curr->left) q.push({curr->left,currHD-1});
        if (curr->right) q.push({curr->right,currHD+1});
    }
    for(auto it:m){
        cout<<it.second<<" ";
    }
}

//kth level of tree
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

//transfrom tree to sum tree
int sumTree(Node* root){
    if(root==NULL) return 0;

    root->data=root->data+sumTree(root->left)+sumTree(root->right);
    return root->data;
}

int main(){
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> pre1 = {1, 2, 6,-1,-1,7,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = builtTree(pre);
    Node* root1 = builtTree(pre1);
    // preOrder(root);
    // inOrder(root);
    // postOrder(root);
    // levelOrder(root);
    // cout<<height(root);
    // cout<<nodes(root);
    // cout<<sum(root);
    // cout<<isSameTree(root,root1);
    // cout<<diameter(root);
    // topView(root);
    // int k=3;
    // kthlevel(root,3);
    // sumTree(root);
    // cout<<root->right->data;
    
}

