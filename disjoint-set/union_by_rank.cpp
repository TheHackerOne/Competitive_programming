#include <bits/stdc++.h>
using namespace std;

int parent[100];

int parentNodeIteration(int a)
{
    while (parent[a] > 0)
        a = parent[a];
    return a;
}

// Path Compression
int parentNodeRecursion(int a)
{
    if (parent[a] < 0)
        return a;
    return parent[a] = parentNodeRecursion(parent[a]);
}

// Union By Rank
void union_sets(int a, int b)
{
    if (parent[a] < parent[b])
    {
        parent[a] += parent[b];
        parent[b] = a;
    }
    else
    {
        parent[b] += parent[a];
        parent[a] = b;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        parent[i] = -1;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a = parentNodeIteration(a);
        b = parentNodeRecursion(b);
        if (a != b)
            union_sets(a, b);
    }
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] < 0)
            product *= abs(parent[i]);
    }
    cout << product;
    system("pause");
    return 0;
}