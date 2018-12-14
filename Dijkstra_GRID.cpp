/*input

*/
//https://devskill.com/CodingProblems/ViewProblem/60


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
char mat[1001][1001];
int n,m;
int dist[1001][1001];
int xxx[]={0,0,-1,1};
int yyy[]={-1,1,0,0};
bool vis[1001][1001];
bool valid(int x,int y){
    return (x<=(n-1) and x>=0 and y>=0 and y<=m-1);
}
int cnt=1;
void dijk(){
    dist[0][0]=0;
    priority_queue<pair<int,ii>,vector<pair<int,ii>>,greater<pair<int,ii>>> pq;
    pq.push({0,{0,0}});
    while(!pq.empty()){
        pair<int,ii> cur = pq.top();
        int curx = cur.second.first,cury = cur.second.second; 
        pq.pop();
         if(vis[curx][cury]) continue;
        vis[curx][cury]=1;
        for(int i=0;i<4;i++){
            int x1 = curx+xxx[i];
            int y1 = cury+yyy[i];
            if(valid(x1,y1) ){
               
            int cost = ((mat[x1][y1]!=mat[curx][cury]));
                if(dist[x1][y1]>dist[curx][cury]+cost){
                    dist[x1][y1]=dist[curx][cury]+cost;
                   // if(vis[curx][cury]) continue;
                    pq.push({dist[x1][y1],{x1,y1}});
                }
            }
        }
    }
    cout<<"Case "<<cnt++<<": "<<dist[n-1][m-1]<<"\n";
    //cout<<n<<" "<<m;

}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
     cin>>n>>m;
    fors(i,0,n){
        fors(j,0,m){
             cin>>mat[i][j];
            //mat[i][j]=(c-'0');
            dist[i][j]=987654321;
            vis[i][j]=0;
        }
    }
    
    dijk();
    }

}
