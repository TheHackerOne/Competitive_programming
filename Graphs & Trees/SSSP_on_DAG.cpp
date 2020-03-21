#include <iostream>
#include<vector>
#include<climits>
#include<map>
#include<algorithm>
using namespace std;

class graph
{

    map<int, vector<pair<int, int>>> adj;
    bool visited[9] = {false};
    vector<int> order;
    int shortest_path[10];

public:
    void shortestPath(int startnode)
    {
        int index;
        for (int i = 0; i <= 7; i++)
        {
            if (order[i] == startnode)
            {
                shortest_path[order[i]] = 0;
                index = i;
            }
            else
                shortest_path[order[i]] = INT_MAX;
        }

        for (int i = index; i < order.size(); i++)
        {
            vector<pair<int, int>> neighbours = adj[order[i]];
            for (int j = 0; j < neighbours.size(); j++)
            {
                int short_path = shortest_path[order[i]] + neighbours[j].second;
                if (shortest_path[neighbours[j].first] > short_path)
                {
                    shortest_path[neighbours[j].first] = short_path;
                }
            }
        }
    }

    void dfs(int n)
    {
        vector<pair<int, int>> neighbour = adj[n];
        visited[n] = true;
        for (int j = 0; j < neighbour.size(); j++)
            if (!visited[neighbour[j].first])
                dfs(neighbour[j].first);
        order.push_back(n);
    }

    void addEdge(int x, int y, int w)
    {
        adj[x].push_back(make_pair(y, w));
    }

    void printTopOrder()
    {
        cout << "\nTopological order = ";
        for (int x : order)
            cout << x << " ";
    }

    void displayShortestPath()
    {
        cout << "\nShortest Path = ";
        for (int i = 1; i < 9; i++)
            cout << shortest_path[i] << " ";
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

    void topsort()
    {
        for (int i = 1; i <= adj.size(); i++)
            if (!visited[i])
                dfs(i);
        reverse(order.begin(), order.end());
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
        // adj[x].make_pair(y,w);
    }
    cin >> startnode;
    g1.topsort();
    g1.printAdjList();
    g1.printTopOrder();
    g1.shortestPath(startnode);
    g1.displayShortestPath();

    system("pause");
    return 0;
}

// TO CALCULATE THE LONGEST PATH FROM A SINGLE SOURCE, JUST NEGATE ALL THE WEIGHTS AND FIND THE SHORTEST     PATH, AND FINALLY MULTIPLY THE FINAL ANSWER WITH "-1"

// 13
// 1 2 3
// 1 3 6
// 2 4 4
// 2 3 4
// 2 5 11
// 3 4 8
// 3 7 11
// 4 5 -4
// 4 6 5
// 4 7 2
// 5 8 9
// 6 8 1
// 7 8 2
// 1