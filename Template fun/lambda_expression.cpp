#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> a={1,12,34,10,23,45,67,34,23,32},b;
    
    // sort(a.begin(),a.end(),[](int x, int y){return (x>y);});
    
    int divisor;
    cin>>divisor;
    // copy_if(a.begin(),a.end(),back_inserter(b),[](int x){return (x%2)==0;});
    copy_if(a.begin(),a.end(),back_inserter(b),[divisor](int x){return (x%divisor)==0;});
                    // OR
    copy_if(a.begin(),a.end(),back_inserter(b),[&](int x){return (x%divisor)==0;});
    
    // for_each(a.begin(),a.end(),[&](int x){b.push_back(x*2);});
    
    for(int u:a)
        cout<<u<<" ";
    cout<<"\n";    
    
    for(int u:b)
        cout<<u<<" ";
    system("pause");
    return 0;
}