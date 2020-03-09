#include<bits/stdc++.h>
using namespace std;

int main()
{
int a[6][6],n,m,steps=0;
for(int i=1;i<6;i++)
{
for(int j=1;j<6;j++)
{
cin>>a[i][j];
if(a[i][j]==1)
n=i,m=j;
}
}
if(n>3)
steps+=n-3;
else if(n<3)  
steps+=3-n;
if(m>3)
steps+=m-3;
else if(m<3) 
steps+=3-m;

cout<<steps;
return 0;
}  
