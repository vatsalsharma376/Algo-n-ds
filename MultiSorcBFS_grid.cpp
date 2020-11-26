//https://codeforces.com/contest/1105/problem/D
#include <bits/stdc++.h>

#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
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
const int sz = 1009;
int s[11],ans[11];
char grid[sz][sz];
int lev[sz][sz];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
queue<ii> q[11];
signed main()
{
	memset(lev,0,sizeof lev);
	memset(ans,0,sizeof ans);
	int n,m,p; 
	cin>>n>>m>>p; //dimensions of grid
	fors(i,1,p) cin>>s[i]; // each cell is of type p(<=9) and can expand till s[i] length
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>grid[i][j];
			if(isdigit(grid[i][j])){
				q[grid[i][j]-'0'].push({i,j});
			}
			//cout<<grid[i][j];
		}
		//cout<<"\n";
	}
	bool fl = 1;
	int r = 0;
	while(fl){
		fl=0;
		++r;
		fors(i,1,p){
			while(!q[i].empty()){
				int x = q[i].front().first;
				int y = q[i].front().second;
				
				if(lev[x][y]>=r*s[i]) break;
				q[i].pop();
				for(int j=0;j<4;j++){
					int xx = x+dx[j],yy=y+dy[j];
					if(xx<0 or xx>=n or yy<0 or yy>=m or grid[xx][yy]!='.') continue;

					grid[xx][yy]='0'+i;
					q[i].push({xx,yy});
					fl=1;
					lev[xx][yy]=1+lev[x][y];
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(isdigit(grid[i][j])){
				++ans[grid[i][j]-'0'];
			}
		}
	}
	fors(i,1,p) cout<<ans[i]<<" ";
	return 0;
}
