#include<iostream>
#include<vector>
#include<queue>
using namespace std;

char a[8][8];
bool visited[8][8];
vector<int> rn={-2,-1,-2,-1,1,2,1,2};
vector<int> cn={-1,-2,-3,2,-2,-1,2,1};
queue<int> r,c;
int nodes_in_next_layer=0;
int nodes_left_in_layer=1;
bool reached_end=false;
int move_to_end=0;

void exploreNeighbours(int rx, int cx)
{
    for(int i=0;i<8;i++)
    {
        int rx1=rx+rn[i];
        int cx1=cx+cn[i];
        
        if(rx1<0 || cx1<0) continue;
        if(rx1>=8 || cx1>=8) continue;
        if(visited[rx1][cx1]) continue;
        
        r.push(rx1);
        c.push(cx1);
        cout<<rx1<<" "<<cx1<<"\n";
        visited[rx1][cx1]=true;
        nodes_in_next_layer++;
    }
}

void bfs(int x1,int y1)
{
    r.push(x1);
    c.push(y1);
    visited[x1][y1]=true;
    while(!r.empty())
    {
        int rr=r.front();
        int cc=c.front();
        r.pop();
        c.pop();
        if(a[rr][cc]=='E') 
        {
            reached_end=true;
            break;
        }
        exploreNeighbours(rr,cc);
        nodes_left_in_layer--;
        if(nodes_left_in_layer==0)
        {
            nodes_left_in_layer=nodes_in_next_layer;
            nodes_in_next_layer=0;
            move_to_end++;
        }
    }
    if(reached_end)
        cout<<"move -> "<<move_to_end<<"\n";
    else 
        cout<<"no path present";    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1;
        cin>>x2>>y2;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                a[i][j]=48;
            }
        }
        a[x1][y1]='S';
        a[x2][y2]='E';
        
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
                visited[i][j]=false;
        }
        bfs(x1,y1);
    }
    system("pause");
    return 0;
}

// 1
// 0 0 starting co-ordinate
// 7 7 ending co-ordinate