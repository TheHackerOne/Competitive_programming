#include<bits/stdc++.h>
using namespace std;

int timer=1;
vector<int> adj[10];
int in[10];
int out[10];
bool visited[10]={false};

void dfs(int node){
    visited[node]=true;
    in[node]=timer++;
    vector<int> neighbour = adj[node];
    for(int i=0;i<neighbour.size();i++){
        if(!visited[neighbour[i]]){
            dfs(neighbour[i]);
        }
    }
    out[node]=timer++;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout<<"IN TIME ";
    for(int i=1;i<=5;i++) cout<<in[i]<<" ";
    cout<<endl;
    cout<<"OUT TIME ";
    for(int i=1;i<=5;i++) cout<<out[i]<<" ";
    system("pause");
    return 0;
}
