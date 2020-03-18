#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;

int leaf(int n) //using DFS
{
    if (adj[n].size() == 0)
        return n;
    vector<int> neighbour = adj[n];
    int total = 0;
    for (int i = 0; i < neighbour.size(); i++)
        total += leaf(neighbour[i]);
    return total;
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
    cout << "Total = " << leaf(5);
    system("pause");
    return 0;
}

// 10 
// 5 4
// 5 3
// 4 1 
// 4 - 6 
// 1 2 
// 1 9 
// 3 0 
// 3 7 
// 3 - 4
// 7 8