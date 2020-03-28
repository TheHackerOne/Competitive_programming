#include "stdc++.h"
using namespace std;

vector<int> adj[10];
bool visited[10] = {false};
int color[20];

bool dfs(int node, int d)
{
    visited[node] = true;
    color[node] = d;
    vector<int> neighbour = adj[node];
    for (int i = 0; i < neighbour.size(); i++)
    {
        if (!visited[neighbour[i]])
        {
            if (!dfs(neighbour[i], d ^ 1))
                return false;
        }
        else
        {
            if (color[node] == color[neighbour[i]])
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (dfs(1, 0)) // '1' is the node and '0' is the color of that node
        cout << "YES";
    else
        cout << "NO";
    system("pause");
    return 0;
}

// 5 
// 1 2 
// 2 3 
// 2 4 
// 4 5 
// 3 4
