// Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect.

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int row,col;
    cin>>row>>col;
    int a[row][col];
    int finalGold[row][col];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>a[i][j];
            
    int right,right_up,right_down;
    
    for(int i=col-1;i>=0;i--)
    {
        for(int j=0;j<row;j++)
        {
            right=(i==col-1)? 0 : finalGold[j][i+1] ;
            right_up=(j==0 || i==col-1)? 0 : finalGold[j-1][i+1] ;
            right_down=(j==row-1 || i==col-1)? 0 : finalGold[j+1][i+1] ;
            
            finalGold[j][i]=a[j][i]+max(right,max(right_down,right_up));
        }
    }
    int res=a[0][0];
    for(int i=1;i<row;i++)
        res=max(res,finalGold[i][0]);
    cout<<res;
    system("pause");
    return 0;
}