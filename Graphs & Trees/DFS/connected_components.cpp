#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool visited[10] = {false};

void dfs(int i)
{
    if (visited[i])
        return;
    visited[i] = true;
    vector<int> neighbours = adj[i];
    for (int i = 0; i < neighbours.size(); i++)
    {
        dfs(neighbours[i]);
    }
}

int main()
{
    int n, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= 8; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            count++;
        }
    }
    cout << "connected components = " << count;
    system("pause");
    return 0;
}

// 12
// 1 2
// 2 3
// 3 4
// 4 1
// 2 1
// 3 2
// 4 3 
// 1 4 
// 5 6 
// 6 5 
// 7 8 
// 8 7