#include <bits/stdc++.h>
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

int Height(bstNode *root)
{
    if (root == NULL)
        return -1;

    return max(Height(root->left), Height(root->right)) + 1;
}

int main()
{
    bstNode *root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 25);
    root = insertNode(root, 8);
    root = insertNode(root, 7);
    root = insertNode(root, 6);
    root = insertNode(root, 12);
    int height = Height(root);
    cout << "Height = " << height << endl;
    system("pause");
    return 0;
}

// #include <vector>
// #include <map>
// #include <set>
// #include <iostream>
// using namespace std;

// map<int, vector<int>> adj;

// int height(int n)
// {
//     if (adj[n].size() == 0)
//         return 0;
//     vector<int> neighbour = adj[n];
//     set<int> x;
//     for (int i = 0; i < neighbour.size(); i++)
//         x.insert(height(neighbour[i]));
//     return *--x.end() + 1;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         adj[x].push_back(y);
//     }
//     cout << "Height = " << height(2);
//     system("pause");
//     return 0;
// }

// 10 
// 2 1 
// 2 3 
// 2 5 
// 2 7 
// 1 0 
// 1 8 
// 5 4 
// 5 6 
// 5 9 
// 0 20