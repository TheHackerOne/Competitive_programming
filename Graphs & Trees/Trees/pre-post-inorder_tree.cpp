#include <iostream>
#include <queue>
using namespace std;

struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};

bstNode *createNode(int data)
{
    bstNode *newNode = new bstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(bstNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(bstNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(bstNode *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bstNode *insertNode(bstNode *root, int data)
{
    if (root == NULL)
        root = createNode(data);

    else if (data <= root->data)
        root->left = insertNode(root->left, data);

    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

int main()
{
    bstNode *root = NULL;
    root = insertNode(root, 100);
    root = insertNode(root, 50);
    root = insertNode(root, 150);
    root = insertNode(root, 20);
    root = insertNode(root, 60);
    root = insertNode(root, 52);
    root = insertNode(root, 120);
    root = insertNode(root, 200);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    system("pause");
    return 0;
}