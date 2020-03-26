// single source shortest path using DFS on trees
// this will only work on trees, not on graphs because they have cycles

#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[10];
bool visited[10]={false};
int distance_from_source[20]={0};

void dfs(int node, int d){
    visited[node]=true;
    distance_from_source[node]=d;
    vector<int> neighbour = adj[node];
    for(int i=0;i<neighbour.size();i++){
        if(!visited[neighbour[i]]){
            dfs(neighbour[i], distance_from_source[node]+1);
        }
    }
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
    dfs(1, 0);
    for(int i=1;i<=5;i++){
        cout<<distance_from_source[i]<<" ";
    }
    return 0;
}

// 4 
// 1 2
// 1 3
// 3 4
// 3 5