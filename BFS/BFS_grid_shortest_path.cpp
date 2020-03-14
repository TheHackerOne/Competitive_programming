#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool reached_end=false;
queue<int> rq,cq;
int nodes_left_in_layer=1;
int nodes_in_next_layer=0;
char m[4][4] = {{0,'*','*',0},
                {'S','*',0,'*'},
                {0,'*','E',0},
                {'*',0,'*','*'}};
bool visited[4][4]={false};
vector<int> re={-1,+1,0,0};
vector<int> ce={0,0,+1,-1};

void exploreNeighbour(int rr, int cc)
{
    for(int i=0;i<4;i++)
    {
        int r=rr+re[i];
        int c=cc+ce[i];
        
        if(r<0 || c<0) continue;
        if(r>=4 || c>=4) continue;
        if(visited[r][c]) continue;
        if(m[r][c]=='*') continue;
        
        visited[r][c]=true;
        nodes_in_next_layer++;
        rq.push(r);
        cq.push(c);
    }
}

int findPath(int sR, int sC)
{   
    int move=0;
    rq.push(sR);
    cq.push(sC);
    visited[sR][sC]=true;
    while(!rq.empty())
    {
        int rr=rq.front();
        rq.pop();
        int cc=cq.front();
        cq.pop();
        if(m[rr][cc]=='E')
        {
            reached_end=true;
            break;
        }
        exploreNeighbour(rr, cc);
        nodes_left_in_layer--;
        if(nodes_left_in_layer==0)
        {
            nodes_left_in_layer=nodes_in_next_layer;
            nodes_in_next_layer=0;
            move+=1;
        }
    }
    if(reached_end)
        return move;
    return -1;      
}

int main()
{   int startR,startC;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(m[i][j]=='S')
            {
                startR=i;
                startC=j;
            }
        }
    }
    int no_of_moves = findPath(startR, startC);
    if(no_of_moves==-1) cout<<"END cannot be reached !!\n";
    else cout<<"MOVES to reach the END = "<<no_of_moves;
    system("pause");
    return 0;
}