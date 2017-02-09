
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
// i know i can join them into one but this looks beautiful :P

vector<vector<int>> gr;
vector<int> state;  
vector<int> parent;
vector<int> tim;
vector<int> low;
vector<int> disc;
vector<bool> vis;
vector<bool> AP; // Articulation points
vector<pair<int,int> > bridge;
// -1 -> Not visisted
// 0  -> Just explored
// 1  -> Fully visited everything
void dfs(int u,int tm){
    vis[u]=true;
    disc[u]=low[u]=tm+1;
    int child=0;
    for(int i=0;i<gr[u].size();i++){
        int v=gr[u][i];
        if(!vis[v]){
            ++child;
            parent[v]=u;
            dfs(v,tm+1);
            low[u]=min(low[u],low[v]);
            if(parent[u]==-1 and child>1){
                AP[u]=true;
            }
            else if(parent[u]!=-1 and low[v]>=disc[u]){
                AP[u]=true;
            }
            if(low[v]>disc[u]) bridge.pb(make_pair(u,v));
        }
        else if(parent[u]!=v) low[u]=min(low[u],disc[v]);
    }
    
}
int main(){
    
    int n,m;
    cin>>n>>m;
    gr.resize(n);
    state.resize(n,-1);
    parent.resize(n,-1);
    tim.resize(n,0);
    low.resize(n,-1);
    disc.resize(n,-1);
    vis.resize(n,false);
    AP.resize(n,false);
    ff(m){
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);gr[y].pb(x);
    
    }
    dfs(0,0);
    
    ff(n){
        if(AP[i]==true) cout<<i<<endl;  // Articulation Points
    }
    ff(bridge.size()){
        cout<<bridge[i].first<<" "<<bridge[i].second<<endl; // Bridgse
    }
    return 0;
}
