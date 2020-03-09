#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long n,k,sum_initial=0,sum_final=0;
	    cin>>n>>k;
	    vector<long long int> a,b;
	    for(long long i=0;i<n;i++)
	    {
	        long long h;
	        cin>>h;
	        sum_initial+=h;
	        a.push_back(h);
	        long long x=(h/k)*k;
	        sum_final+=x;
	        b.push_back(x);
	    }
	    long sum=sum_initial-sum_final;
	    long j=sum%k;
	    cout<<j<<"\n";
	}
	return 0;
}
