#include<iostream>
#include<queue>
using namespace std;

struct bstNode{
  int data;
  bstNode *left;
  bstNode *right;
};

bstNode *createNode(int data){
    bstNode *newNode = new bstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void bfs(bstNode *root){
    if(root==NULL)
        return;
    queue<bstNode*> q;
    q.push(root);
    while(!q.empty()){
        bstNode *node = q.front();
        q.pop();
        cout<<node->data<<"\n";
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
    }
}

bstNode *insertNode(bstNode *root, int data){
    if(root == NULL)
        root = createNode(data);
        
    else if(data <= root->data)
        root->left = insertNode(root->left, data);
        
    else if(data > root->data)
        root->right = insertNode(root->right, data);
        
    return root;        
}

int main(){
    bstNode *root = NULL;
    root = insertNode(root, 100);
    root = insertNode(root, 50);
    root = insertNode(root, 150);
    root = insertNode(root, 20);
    root = insertNode(root, 60);
    root = insertNode(root, 52);
    root = insertNode(root, 120);
    root = insertNode(root,200);
    bfs(root); 
    system("pause");   
    return 0;
}