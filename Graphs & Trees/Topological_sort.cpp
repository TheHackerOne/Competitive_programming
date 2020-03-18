#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// for DIRECTED ACYCLIC GRAPHS (DAG)
map<int, vector<int>> adj;
int ordering[14];
int n = 13;

void dfs(int startNode, bool *visited)
{
    visited[startNode] = true;
    vector<int> neighbour = adj[startNode];
    for (int i = 0; i < neighbour.size(); i++)
    {
        if (!visited[neighbour[i]])
        {
            dfs(neighbour[i], visited);
        }
    }
    cout << "ordering " << n << " = " << startNode << "\n";
    ordering[n] = startNode;
    n -= 1;
}

void topsort(int nodes)
{
    bool visited[nodes] = {false};
    for (int i = 1; i <= nodes; i++)
        if (!visited[i])
            dfs(i, visited);
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
    int nodes = adj.size();
    topsort(nodes);
    cout<<"Topological Order = ";
    for (int i = 1; i <= 13; i++)
        cout << ordering[i] << " ";
    cout<<"\n";    
    system("pause");
    return 0;
}

// 18 
// 8 10 
// 1 4 
// 2 4 
// 3 1 
// 3 2 
// 4 7 
// 4 8 
// 5 4 
// 5 6 
// 5 1 
// 6 10 
// 6 11 
// 7 9 
// 8 9 
// 9 12 
// 10 12 
// 10 13 
// 11 10
