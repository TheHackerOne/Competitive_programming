#include<iostream>
#include<queue>
using namespace std;
vector<int> a[12];
bool visited[12]={false};

void bfs(int n)
{
    queue<int> m;
    m.push(n);
    visited[n]=true;
    int route[12];
    while(!m.empty())
    {
        int node=m.front();
        m.pop();
        vector<int> neighbour=a[node];
        for(int i=0;i<neighbour.size();i++)
        {
            if(!visited[neighbour[i]])
            {
                cout<<"from "<<node<<" to "<<neighbour[i]<<"\n";
                m.push(neighbour[i]);
                visited[neighbour[i]]=true;
                route[neighbour[i]]=node;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) // To take an adjacency list
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
    }
    for(int i=0;i<12;i++) //To display adjacency list
    {    cout<<i<<" -> ";
        for(int j=0;j<a[i].size();j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";    
    }
    bfs(0); // Starting BFS traversal with node 0
    system("pause");
    return 0;
}