
#include <bits/stdc++.h>

#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define new cout<<endl
#define ff(n) for(int i=0;i<n;i++)
#define all(v) sort(v.begin(),v.end())

using namespace std;
vector<int> parent;
vector<pair<int,pair<int,int> > >grp;
int par (int v) {
    return (v == parent[v])?  v : (parent[v] = par(parent[v]));
}
void uni(int a,int b){
    a=par(a);
    b=par(b);       // no rank compression
    
    if(a!=b){
        parent[a]=b;
    }
}
bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    return a.first<b.first;
}
vector<ii> result;
int main(){
        int n,m;
        cin>>n>>m;
        parent.resize(n);
        ff(n) parent[i]=i;
        
        ff(m){
            int x,y,w;
            cin>>x>>y>>w;
            grp.pb(make_pair(w,make_pair(x,y)));    // undirected graph
            grp.pb(make_pair(w,make_pair(y,x)));
        }
        sort(grp.begin(),grp.end(),cmp);
        ll int cost=0;
        ff(grp.size()){
            int x=grp[i].second.first;
            int y=grp[i].second.second;
            int l=grp[i].first;
            if(par(x)!=par(y)){
                cost+=l;
                result.pb(make_pair(x,y));  // answers
                
                uni(x,y);
            }
        
        }
        cout<<cost;
    return 0;
}
