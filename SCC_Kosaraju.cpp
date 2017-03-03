#include<bits/stdc++.h>
#define V 5000	// max no of vertices
using namespace std;
vector<int > adj[V];//Adjency List Representation
vector<int> adj_rev[V];
bool visit[V];
stack <int > mystack;
 
void set_false()
{
    for(int i=0;i<V;i++)
        visit[i]=false;//Mark visit array as False;
}
void dfs_order(int s)
{
    visit[s]=true;
    for(int i=0;i<adj[s].size();++i)
            if(visit[adj[s][i]]==false)    
                dfs_order(adj[s][i]);
    mystack.push(s);
}
void dfs(int s)
{
    visit[s]=true;
    cout<<s<<" ";
    for(int i=0;i<adj_rev[s].size();++i)
            if(visit[adj_rev[s][i]]==false)   
             dfs(adj_rev[s][i]);
 
 
}
int main()
{
    int node,edge,x,y,c=0;
    cin>>node>>edge;
    set_false();
    for(int i=0;i<edge;i++)
    {
     cin>>x>>y;
     adj[x].push_back(y);
     adj_rev[y].push_back(x);//Reverse of given graph
    }
 
 for(int i=1;i<=node;i++)
 if(visit[i]==false)
   dfs_order(i); // vertices in order of completion of the recursive calls.
 
   set_false();
   while(!mystack.empty())
   {
   int v=mystack.top();
     mystack.pop();
     if(visit[v]==false)
     {
        dfs(v);
        c++;
        cout<<"\n";
     }
   }
   //cout<<"Number of Components :"<<c;
}
