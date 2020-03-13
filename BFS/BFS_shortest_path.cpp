#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> a[12];
vector<int> path;
bool visited[12] = {false};

bool shortpath(int start, int end, int route[])
{
    for (int i = end; i != start; i = route[i])
    {   cout<<route[i]<<" ";
        path.push_back(route[i]);
    }

    reverse(path.begin(), path.end());
    if (path[0] == start)
        return true;
    return false;
}

void bfs(int startNode, int endNode)
{
    queue<int> m;
    m.push(startNode);
    visited[startNode] = true;
    int route[12] = {-1};
    while (!m.empty())
    {
        int node = m.front();
        m.pop();
        vector<int> neighbour = a[node];
        for (int i = 0; i < neighbour.size(); i++)
        {
            if (!visited[neighbour[i]])
            {
                // cout << "from " << node << " to " << neighbour[i] << "\n";
                m.push(neighbour[i]);
                visited[neighbour[i]] = true;
                route[neighbour[i]] = node;
            }
        }
    }

    bool Spath = shortpath(startNode, endNode, route);

    if (Spath)
    {
        cout << "\nPath = ";
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " -> ";
        cout << endNode<<"\n";
    }
    else
    {
        cout << "Shortest path does not exist";
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    int endNode,startNode;
    // cout << "Enter the End Node = ";
    cin>>startNode;
    // cout<<"Enter the start Node = ";
    cin >> endNode;
    bfs(startNode, endNode);
    system("pause");
    return 0;
}

// TEST INPUT
// 28
// 0 1
// 0 9
// 1 0
// 1 8
// 2 3
// 3 2
// 3 4
// 3 5
// 3 7
// 4 3
// 5 3 
// 5 6
// 6 5
// 6 7
// 7 8
// 7 10
// 7 11
// 7 6
// 7 3
// 8 1
// 8 7
// 8 9
// 9 0
// 9 8
// 10 7
// 10 11
// 11 7
// 11 10
// 1 
// 11
