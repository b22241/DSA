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

void levelorder(Node* root) {
    if (root == NULL) return; 
    queue<Node*> q;
    q.push(root);
    vector<vector<int>>ans;

    while (!q.empty()) {
        vector<int>t;
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* curr = q.front();
            q.pop();
            t.push_back(curr->data);
            
            if(curr->left) q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        ans.push_back(t);

    }
    for(auto i:ans){
        for(auto j:i){
            cout<<j;
        }
        cout<<endl;
    }
}
//travel levelwise from left to right and then right to left
void zigZagTraversal(Node* root) {
    vector<int> result;
    if (root == NULL)
        return ;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> ans(size);

        // Level Process
        for (int i = 0; i < size; i++) {
            Node* frontNode = q.front();
            q.pop();

            // Find index based on direction
            int index = leftToRight ? i : (size - i - 1);
            ans[index] = frontNode->data;

            // Push children into queue
            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }

        // Add current level to result
        for (int i = 0; i < size; i++)
            result.push_back(ans[i]);

        // Change direction
        leftToRight = !leftToRight;
    }
    for(auto i:result){
        cout<<i;
    }
}

//last level 
void lastLevel(Node* root,vector<int>&ans) {
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    lastLevel(root->left,ans);
    lastLevel(root->right,ans);
}

//perripheral traversal
void boundryTraversal(Node* root){
    vector<int>res;
    Node* temp1=root;
    while(temp1->left ){
        res.push_back(temp1->data);
        if(temp1->left){
            temp1=temp1->left;
        }
        else if(temp1->right){
            temp1=temp1->right;
        }
    }
    vector<int>ans;
    lastLevel(root,ans);
    for(auto i:ans){
        res.push_back(i);
    }
    vector<int>t;
    while(root){
        t.push_back(root->data);
        if(temp1->right){
            temp1=temp1->right;
        }
        else if(temp1->left){
            temp1=temp1->left;
        }
    }
    reverse(t.begin(),t.end());
    for(int i=0;i<t.size()-1;i++){
        res.push_back(t[i]);
    }
    for(auto i:res){
        cout<<i<<"-";
    }
}

//left view of tree
vector<int> leftView(Node *root) {
        // code here
         vector<int> ans;
        if (root == NULL) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();

                // push the last node of each level
                if (i ==0) ans.push_back(curr->data);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return ans;
}

//diagonal traversal of a tree
vector<int> diagonal(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        map<int, vector<int>> diag;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto pr = q.front();
            q.pop();

            Node* node = pr.first;
            int d = pr.second;

            // Traverse the whole right chain for this node,
            // collecting nodes on the same diagonal and enqueueing left children.
            while (node) {
                diag[d].push_back(node->data);

                if (node->left) {
                    q.push({node->left, d + 1});
                }

                node = node->right; // move along the right to stay on same diagonal
            }
        }

        // flatten map in order of diagonal (0,1,2,...)
        for (auto &p : diag) {
            for (int v : p.second) ans.push_back(v);
        }

        return ans;
}

//height of tree
int height(Node* root){
    if(root->data==-1){
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
int diameter(Node* root) {
        if(!root) return 0;
        int leftDia = diameter(root->left);
        int rightDia = diameter(root->right);
        int rootDia=height(root->left)+height(root->right);
        return max(rootDia, max(leftDia,rightDia));
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

Node* inorderPredecor(Node* root){             //IP is the right most element in left subtree of that element
    if(root==NULL) return root;
    Node* IP=root->left;
    while(IP->right!=NULL && IP->right!=root ){
        IP=IP->right;
    }
    return IP;
}

//Morris Inorder Traversal          --left,root,right
void morrisInorder(Node* root){
    Node* curr=root;
    while(curr){
    if(curr->left==NULL){
        cout<<curr->data;
        curr=curr->right;
    }
    else{
        Node* IP=inorderPredecor(curr);
        if(IP->right==NULL){
            IP->right=curr;
            curr=curr->left;
        }
        else{
            IP->right==NULL;
            cout<<curr->data;
            curr=curr->right;
        }
    }
}
}

//flatten binary tree to linked list
Node* nextRight=NULL;
void flatten(Node* root){
    if(root==NULL) return ;
    
    flatten(root->right);
    flatten(root->left);

    root->left=NULL;
    root->right=nextRight;
    nextRight=root;
}

int main(){
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> pree = {8,4,3,3,-1,-1,-2,2,-1,1,-1,-1,5,-1,2,-1,-1};
    int i = -1;
    Node* root = builtTree(pre,i);
    // cout<<2;
    // Node* roott = builtTree(pree,i);
    preOrder(root);
    // inOrder(root);
    // postOrder(root);
    // levelOrder(root);
    // boundryTraversal(root);
    // cout<<height(root);
    // levelorder(root);
    // cout<<nodes(root);
    // cout<<sum(root);
    // cout<<isSameTree(root,root1);
    // cout<<diameter(root);
    // topView(root);
    // int k=3;
    // kthlevel(root,3);
    // sumTree(root);
    // cout<<root->right->data;
    // morrisInorder(root);
    // flatten(root);
    
    
}

