#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    long long int sum=0;
	    cin>>n;
	    vector<long long int> a,b;
	    for(int i=0;i<n;i++)
	    {
	        long long h;
	        cin>>h;
	        a.push_back(h);
	    }
	    for(int i=0;i<n;i++)
	    {
	        long long h;
	        cin>>h;
	        b.push_back(h);
	    }
	    sort(a.begin(),a.end());
	    sort(b.begin(),b.end());
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]<b[i])
	        {
	            sum+=a[i];
	        }
	        else{
	            sum+=b[i];
	        }
	    }
	    cout<<sum<<"\n";
 	}
	return 0;
}
