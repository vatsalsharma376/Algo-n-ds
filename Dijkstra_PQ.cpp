/*input
4 4
1 2
1 3
3 4
2 3
*/

#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define putcx putchar_unlocked
#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define int long long int
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define lines printsf("\n")
#define ff(n) for(int i=0;i<n;i++)
#define fors(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(),v.end()
#define mp make_pair
using namespace std;
const int MOD = 1e9+7;
vector<ii> grp[100];  //        MODIFY THE LIMITS
vi dist(100,INT_MAX);
vi visited(100,0);
void dijk(int s){
	dist[s]=0;
	priority_queue<ii,vector<ii>,greater<ii>> mypq;
	mypq.push(make_pair(0,s));
	while(!mypq.empty()){
		ii cur = mypq.top();
		mypq.pop();
		int curn = cur.second;
		int curd = cur.first;
		if(visited[curn]) continue;
		visited[curn]=1;
		for(auto i:grp[curn]){
			if(visited[i.second]==0 and dist[i.second]>curd+i.first){
				dist[i.second] = curd+i.first;
				mypq.push(make_pair(dist[i.second],i.second));
			}
		}

	}

}
signed main(){

	int n,m;
	cin>>n>>m;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		--u; --v;
		grp[u].push_back(make_pair(w,v));
	}
	dijk(0);
	ff(n) cout<<dist[i]<<" ";

}
