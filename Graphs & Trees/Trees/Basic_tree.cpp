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

bool searchNode(bstNode *root, int data)
{
    if (root == NULL)
        return false;

    if (data == root->data)
        return true;

    if (data < root->data)
        return searchNode(root->left, data);

    if (data > root->data)
        return searchNode(root->right, data);
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
    int number;
    cout << "Enter number be searched\n";
    cin >> number;
    if (searchNode(root, number))
        cout << "Found\n";
    else
        cout << "Not Found\n";
    system("pause");
    return 0;
}