#include <iostream>
using namespace std;

// Disjoint set

int parent[100];

// function to find parent node of a node
// path compression implementation
int findParent(int a)
{
    if(parent[a]<0) return a;
    return parent[a]=findParent(parent[a]);
}

// function to do union of two sets( connect two sets )
void union1(int a, int b)
{
    parent[a] = parent[a] + parent[b];
    // cout<<"Parent -> "<<parent[a]<<"\n";
    parent[b] = a;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = -1;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a = findParent(a);
        b = findParent(b);
        if (a != b)
            union1(a, b);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] < 0)
            ans *= abs(parent[i]);
    }
    cout << ans << "\n";
    system("pause");
    return 0;
}
