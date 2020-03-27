#include<vector>
#include<iostream>
using namespace std;

vector<int> adj[10];
bool visited[10]={false};
int parent[10];

bool cycle_detection(int node, int par){
    visited[node]=true;
    parent[node]=par;
    vector<int> neighbour = adj[node];
    for(int i=0;i<neighbour.size();i++){
        if(!visited[neighbour[i]]){
            if(cycle_detection(neighbour[i], node))
                true;
        }else{
            if(neighbour[i]!=par)
                return true;
        }
    }
    return false;
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
    cycle_detection(1, 0) ? cout<<"Cycle Detected !!" : cout<<"No Cycle Detected !!";
    system("pause");
    return 0;
}