#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	
	multiset <int> s;
	multiset<int>:: iterator it;
	int n;
	cin>>n;
	int x;
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
