#include <bits/stdc++.h>
using namespace std;

int main() {
	
	multiset <int> s;
	multiset<int>:: iterator it;
	int n,x
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		s.insert(x);
		it=s.upper_bound(x);
		if(it!=s.end())s.erase(it);
	}
	cout<<s.size();
	return 0;
}
