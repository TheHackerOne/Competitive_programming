#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <climits>
using namespace std;

class graph
{

    map<int, vector<pair<int, int>>> adj;
    bool visited[9] = {false};
    int weight[10];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

public:
    void shortestPath(int startnode)
    {
        int index;
        for (int i = 1; i <= 8; i++)
            weight[i] = INT_MAX;
        weight[startnode] = 0;
        q.push(make_pair(weight[startnode], startnode));

        while (!q.empty())
        {
            auto Top = q.top();
            int node = Top.second;
            q.pop();
            visited[node] = true;
            vector<pair<int, int>> neighbour = adj[node];
            for (int i = 0; i < neighbour.size(); i++)
            {
                if (weight[neighbour[i].first] > weight[node] + neighbour[i].second)
                {
                    weight[neighbour[i].first] = weight[node] + neighbour[i].second;
                    q.push(make_pair(weight[neighbour[i].first], neighbour[i].first));
                }
            }
        }
    }

    void addEdge(int x, int y, int w)
    {
        adj[x].push_back(make_pair(y, w));
    }

    void displayShortestPath()
    {
        cout << "\nShortest Path = ";
        for (int i = 1; i < 9; i++)
            cout << weight[i] << " ";
    }

    void printAdjList()
    {
        for (int i = 1; i <= adj.size(); i++)
        {
            cout << i << " -> ";
            for (int j = 0; j < adj[i].size(); j++)
                cout << adj[i][j].first << " ";
            cout << "\n";
        }
    }
};

int main()
{
    graph g1;
    int n, startnode, index;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g1.addEdge(x, y, w);
    }
    cin >> startnode;
    g1.printAdjList();
    g1.shortestPath(startnode);
    g1.displayShortestPath();
    system("pause");
    return 0;
}