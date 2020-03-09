#include<iostream>
using namespace std;

long int factorial(int n){
    cout<<"calculating f("<<n<<")"<<"\n";
    if(n==0){
        return 1;
    }
    long int F=n*factorial(n-1);
    cout<<"f("<<n<<") = "<<F<<"\n";
    return F;
}

int main(){
    int n;
    cin>>n;
    long int fact = factorial(n);
    cout<<"FACTORIAL = "<<fact<<"\n";
    system("pause");
    return 0;
}