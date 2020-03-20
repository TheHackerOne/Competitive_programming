#include<iostream>
#include<map>
#include<list>
#include<vector>
using namespace std;

template <typename T>

class graph{
    map<T, vector<T>> g;
    
public:
    void addEdge(T u, T v, bool bidir)
    {
        g[u].push_back(v);
        if(bidir){
            g[v].push_back(u);
        }
    }
    
    void printEdge()
    {
        for(auto row:g)
        {   auto key=row.first; // we can use auto or T
            cout<<key<<" -> ";
            for(auto ele:row.second)
                cout<<ele<<" ";
            cout<<"\n";    
        }
    }
    
};

int main()
{
    graph<string> g1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string x,y;
        cin>>x>>y;
        g1.addEdge(x,y,true);
    }
    // g1.addEdge(0,1,true);
    // g1.addEdge(0,2,true);
    // g1.addEdge(1,2,true);
    g1.printEdge();
    system("pause");
    return 0;
}