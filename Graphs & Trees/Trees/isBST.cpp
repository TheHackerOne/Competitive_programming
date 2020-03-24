#include <iostream>
#include <climits>
using namespace std;

struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};

bstNode *newNode(int data)
{
    bstNode *newNode = new bstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bstNode *insertNode(bstNode *root, int data)
{
    if (root == NULL)
        root = newNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);

    if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

bool isBST(bstNode *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->data > min && root->data < max && isBST(root->left, min, root->data) && isBST(root->right, root->data, max))
        return true;
    else
        return false;
}

int main()
{
    bstNode *root = NULL;
    root = insertNode(root, 100);
    root = insertNode(root, 50);
    root = insertNode(root, 150);
    if (isBST(root, INT_MIN, INT_MAX))
        cout << "GIVEN TREE IS A BINARY SEARCH TREE\n";
    else
        cout << "NOT A BINARY SEARCH TREE";
    system("pause");
    return 0;
}