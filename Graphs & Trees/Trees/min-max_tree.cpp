#include <iostream>
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

bstNode *insertNode(bstNode *root, int data)
{
    if (root == NULL)
        root = createNode(data);

    else if (data <= root->data)
        root->left = insertNode(root->left, data);

    else if (data >= root->data)
        root->right = insertNode(root->right, data);

    return root;
}

int min(bstNode *root)
{
    if (root == NULL)
    {
        cout << "TREE is empty\n";
        return -1;
    }

    if (root->left == NULL)
        return root->data;

    return min(root->left);
}

int max(bstNode *root)
{
    if (root == NULL)
    {
        cout << "TREE is empty\n";
        return -1;
    }

    if (root->right == NULL)
        return root->data;

    return max(root->right);
}

int main()
{
    bstNode *root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 25);
    root = insertNode(root, 8);
    root = insertNode(root, 12);
    int maximum = max(root);
    if (maximum != -1)
        cout << "maximum = " << maximum << endl;
    int minimum = min(root);
    if (minimum != -1)
        cout << "minimum = " << minimum << endl;
    system("pause");
    return 0;
}