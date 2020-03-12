#include<iostream>
#include<vector>
using namespace std;

bool visited[100]={false};
vector<int> a[5];
void dfs(int n)
{
    if(visited[n])
    {
        cout<<"already visited = "<<n<<" so return \n";
        return;
    }
    visited[n]=true;
    vector<int> neighbour=a[n];
    for(int i=0;i<neighbour.size();i++)
    {
        cout<<"visited = "<<neighbour[i]<<"\n";
        dfs(neighbour[i]);
    }
    
}

int main()
{
    int m;
    cin>>m;
    
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);   
    }
    cout<<"visited = "<<0<<"\n";
    dfs(0);
    return 0;
}


