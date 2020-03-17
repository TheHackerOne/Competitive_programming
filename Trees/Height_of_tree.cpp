#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

map<int, vector<int>> adj;

int height(int n)
{
    if (adj[n].size() == 0)
        return 0;
    vector<int> neighbour = adj[n];
    set<int> x;
    for (int i = 0; i < neighbour.size(); i++)
        x.insert(height(neighbour[i]));
    return *--x.end() + 1;
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
    cout << "Height = " << height(2);
    system("pause");
    return 0;
}

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