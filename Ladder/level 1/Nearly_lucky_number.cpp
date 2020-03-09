#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a;
    cin>>a;
    int count=0;
    auto s=to_string(a);
    bool an=false;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='7' || s[i]=='4')
        {
            count++;
        }
        else
        continue;
    }
    
    auto ans=to_string(count);
    for(int i=0;i<ans.length();i++)
    {
        if(ans[i]=='7' || ans[i]=='4')
        continue;
        else
        {
            an=true;
            break;
        }
    }
    if(an)
    cout<<"NO";
    else
    cout<<"YES";
    return 0;
}      