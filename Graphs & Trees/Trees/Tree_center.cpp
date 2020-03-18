#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std;

map<int, vector<int>> adj;

void center()
{
    int nodes = adj.size();
    int degree[20];
    vector<int> leaf;
    int count = 0;
    for (int i = 0; i < nodes; i++)
    {
        degree[i] = adj[i].size();
        if (degree[i] == 1)
        {
            leaf.push_back(i);
            degree[i] = 0;
        }
    }
    count = leaf.size();
    while (count < nodes)
    {
        vector<int> new_leaf;
        for (int i = 0; i < leaf.size(); i++)
        {
            vector<int> neighbour = adj[leaf[i]];
            for (int j = 0; j < neighbour.size(); j++)
            {
                degree[neighbour[j]] = degree[neighbour[j]] - 1;
                if (degree[neighbour[j]] == 1)
                    new_leaf.push_back(neighbour[j]);
            }
            degree[i] = 0;
        }
        count += new_leaf.size();
        leaf = new_leaf;
    }
    for (int x : leaf)
        cout << x;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    center();
    system("pause");
    return 0;
}