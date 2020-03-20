#include<iostream>
using namespace std;

int a[50];

int fib(int n)
{
    if(n<=1)
        return n;
    if(a[n]!=-1)
        return a[n];
    a[n]=fib(n-1)+fib(n-2);
    return a[n];        
}

int main(){

    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        a[i]=-1;
    }
    cout<<"Sum of Fibonaaci series using Memoization = "<<fib(n)<<"\n";
    for(int i=0;i<=n;i++)
    {
        cout<<"F["<<i<<"] = "<<a[i]<<"\n";
    }
    system("pause");
    return 0;
}