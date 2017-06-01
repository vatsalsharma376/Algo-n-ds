// LCA http://www.spoj.com/problems/LCA/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second

#define N 1000
#define LG 25

int P[N+5][LG+5];
int par[N+5], lev[N+5];
vector <int> v[1001];

void init()
{
	memset(P, -1, sizeof(P));
	memset(par, -1, sizeof(par));
	for (int i = 0; i <= N; ++i) v[i].clear();
}

void insert(int x)
{
	P[x][0] = par[x];
	for (int j = 1; j < LG; ++j) {
		if (P[x][j-1] != -1) {
			P[x][j] = P[P[x][j-1]][j-1];
		}
	}
}

int LCA(int x, int y)
{
	int dif, i, j, k;

	if (lev[x] < lev[y]) swap(x, y);
	dif = lev[x] - lev[y];
	for (i = 0; i < LG; ++i) {
		if (dif&(1<<i)) {
			x = P[x][i];
		}
	}

	if (x == y) return x;

	for (i = LG; i >= 0; --i) {
		if (P[x][i] != -1 && P[x][i] != P[y][i]) {
			x = P[x][i];
                        y = P[y][i];
		}
	}

	return par[x];
}

int main()
{
	int t, n, m, i, j, k, x, y;

	sci(t);
	for (j = 1; j <= t; ++j) {
		printf("Case %d:\n", j);
		init();
		sci(n);
		for (i = 1; i <= n; ++i) {
			sci(m);
			while (m--) {
				sci(x);
				par[x] = i;
				v[i].pb(x);
			}
		}

		queue <int> q;
		q.push(1);
		lev[1] = 1;
		while (!q.empty()) {
			x = q.front(); q.pop();
			insert(x);
			if (x != 1) lev[x] = lev[par[x]]+1;
			for (i = 0; i < v[x].size(); ++i) q.push(v[x][i]);
		}

		sci(k);
		while (k--) {
			sci(x); sci(y);
			printf("%d\n", LCA(x, y));
		}
	}

	return 0;
}
