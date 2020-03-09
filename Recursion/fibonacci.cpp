#include<iostream>
using namespace std;

long int fibo(int n)
{
    int f1=0, f2=1, f=0;
    for(int i=2;i<=n;i++)
    {
        f=f1+f2;
        f1=f2;
        f2=f;
    }
    return f;
}

long int fib(int n)
{
    if(n<=1)
        return n;
    return fib(n-1) + fib(n-2);
}

int sum(int n)
{
    if(n==1)
        return 1;
    return n + sum(n-1);    
}

int main(){

    int n;
    cin>>n;
    
    // fibonacci using iterative method
    cout<<"Fibonaaci sum using ITERATIVE method = "<<fibo(n)<<"\n";

    // fibonacci using recursion method
    cout<<"Fibonaaci using RECURSION method = "<<fib(n)<<"\n";

    // sum of first n natural numbers using recursion
    cout<<"sum of first "<<n<<" numbers = "<<sum(n)<<"\n"<<(n*(n+1))/2<<"\n";
    
    // recursion is not useful here because recursion tree will be formed which will lead to redundant computation of same f(n) multiple times

    system("pause");
    return 0;
}