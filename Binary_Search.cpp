#include <bits/stdc++.h>
// CF PROBLEM : https://codeforces.com/contest/803/problem/D
#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define int long long int
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define lines printsf("\n")
#define ff(n) for(int i=0;i<n;i++)
#define fors(i,a,b) for(int i=a;i<=b;i++)
#define all(v) v.begin(),v.end()


using namespace std;
std::vector<string> wds;
int n;
//std::vector<string> words;
bool check(int k){
	int req=0,temp=0;
	for(auto s:wds){
		if(s.size()>k) return 0;
		if(temp+(int)s.size()>k){
			temp=0; ++req;
		}
		temp+=(int)s.size();
	}
	++req;
	return (req<=n);
}
void solve(){
	cin>>n;
	string s; getline(cin,s); getline(cin,s);
	string cur="";
	ff(s.size()){
		cur+=s[i];
		if(s[i]==' ' or s[i]=='-'){
			wds.push_back(cur); cur.clear();
		}
	}
	wds.push_back(cur);
	int l=0,r=(int)s.size();
	while(l<=r){
		int mid = l + ((r-l)/2);
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l;

}

signed main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
