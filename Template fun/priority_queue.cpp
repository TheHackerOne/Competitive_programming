#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> x;
	x.push(make_pair(10,0));
	x.push(make_pair(30,1));
	x.push(make_pair(20,2));
	x.push(make_pair(23,3));
	for(int i=0;i<4;i++)
	{
        auto k=x.top();
	    cout<<k.first<<" "<<k.second<<"\n";
	    x.pop();
	}
	return 0;
}


// for 2d array using vector
vector<int> a[10];
a[i].push_back(c);

// mapping of an integer to a vector/list/stack etc
map<int , vector<int>> m;