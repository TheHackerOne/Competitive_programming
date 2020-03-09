#include<bits/stdc++.h>

using namespace std;
int main()
{
int n;
cin>>n;
int a[n][3];
for(int i=0;i<n;i++)
{
for(int j=0;j<3;j++)
{
cin>>a[i][j];
}
}
int x=0, y=0, z=0;
for(int i=0;i<3;i++)
{
for(int j=0;j<n;j++)
{
if(i==0)
x+=a[j][i];
else if(i==1)
y+=a[j][i];
else if(i==2)
z+=a[j][i];    
}
}
if(x==0 && y==0 && z==0)
cout<<"YES";
else
cout<<"NO";
return 0;
}