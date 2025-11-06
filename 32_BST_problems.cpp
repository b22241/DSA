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

// Build tree from preorder with -1 as NULL
Node* builtTree(vector<int>& arr, int &i) {
    i++;
    if (arr[i] == -1) return NULL;

    Node* root = new Node(arr[i]);
    root->left = builtTree(arr, i);
    root->right = builtTree(arr, i);
    return root;
}

// Pass map by reference
void findParent(Node* root, map<Node*,Node*> &m, Node* parent){
    if(root == NULL) return;
    
    m[root] = parent;   // store parent
    
    findParent(root->left, m, root);
    findParent(root->right, m, root);
}

int levels(Node* root){
    if (root==NULL) return 0;
    
    queue<Node*>q;
    int level=0;
    q.push(root);
    while(!q.empty()){
        
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        level++;
    }
    return level;
}

int main(){
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int i = -1;
    Node* root = builtTree(pre, i);

    // map<Node*,Node*> m;
    // findParent(root, m, NULL);

    // cout << "Node -> Parent\n";
    // for(auto p : m){
    //     cout << p.first->data << " -> ";
    //     if(p.second) cout << p.second->data;
    //     else cout << "NULL";
    //     cout << endl;
    // }
    cout<<levels(root->right);
}
