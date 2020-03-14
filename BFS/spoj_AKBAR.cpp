// https://www.spoj.com/problems/AKBAR/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(long long n,long long strength[], vector<long long> *a, vector<long long> &soldiers_at_node)
{  
    queue<long long> m;
    bool visited[100]={false};
    long long layers_to_scan=strength[n];
    if(layers_to_scan==-1)
        return;
    if(layers_to_scan==0)
    {
            soldiers_at_node[n]++;
            return;
    }
    m.push(n);
    visited[n]=true;
    soldiers_at_node[n]+=1;
    while(layers_to_scan!=0)
    {   
        long long poped_node=m.front();
        m.pop();
        vector<long long> neighbours=a[poped_node];
        for(long long i=0;i<neighbours.size();i++)
        {
                visited[neighbours[i]]=true;
                soldiers_at_node[neighbours[i]]+=1;
        }
        layers_to_scan--;
    }
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {   vector<long long> soldierz_at_node(100, 0);
        long long r,m,node;
        vector<long long> a[100];
        long long strength[100];
        cin>>node>>r>>m;
        for(long long i=1;i<=node;i++)
            strength[i]=-1;
        for(long long i=0;i<r;i++)
        {
            long long x,y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for(long long i=0;i<m;i++)
        {
            long long x,y;
            cin>>x>>y;
            strength[x]=y;
        }
        for(long long i=1;i<=node;i++)
            bfs(i, strength, a, soldierz_at_node);
        long long count=0;    
        for(long long i=1;i<=node;i++)
            if(soldierz_at_node[i]==1)
                count++;
        if(count==node) 
            cout<<"Yes\n"; 
        else cout<<"No\n";
    }
    system("pause");
    return 0;
}

// 2
// 4 5 2
// 1 4
// 1 2
// 1 3
// 4 2
// 3 4
// 2 1
// 3 0
// 3 2 2
// 1 2
// 2 3
// 1 2
// 2 0