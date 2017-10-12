/*input
7 7
0 1 2
0 4 2
1 2 1
1 3 2
4 5 2
5 6 1
3 6 0
*/
#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define putcx putchar_unlocked
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
#define lines printf("\n")
#define ff(n) for(int i=0;i<n;i++)
#define fors(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(),v.end()
using namespace std;
#define MAXV 1234
int mat[MAXV][MAXV];

int main()
{
    //floyd warshall by first converting adjacency list to adjacency matirx
    int n,m;
    cin>>n>>m;
    for(int i=0;i<MAXV;i++){
        for(int j=0;j<MAXV;j++){
            mat[i][j]=INT_MAX;
            if(i==j) mat[i][j]=0;
        }
    }
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        mat[u][v]=w;
        mat[v][u]=w;
    }
    fors(k,0,n){
        fors(i,0,n){
            fors(j,0,n){
                if(mat[i][k]!=INT_MAX and mat[k][j]!=INT_MAX)mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);//for overflow
            }
        }
    }
    cout<<mat[3][6];//shortest distance between 3 and 6
    return 0;
}
