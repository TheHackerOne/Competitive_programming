#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin>>n>>t;
    char a[n];
    char h;
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]=='B' && a[j+1]=='G')
            {
                char temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                j+=1;
            }
            else
            continue;
        }
    }
    for(char x:a)
    cout<<x;
    return 0;
}