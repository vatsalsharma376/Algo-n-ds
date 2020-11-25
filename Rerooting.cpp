//https://codeforces.com/contest/1092/problem/F 
// changing root from u to v changes sum[v](sum under a subtree) and res(total distance to root*a[v] of each node) 
#include <bits/stdc++.h>

using namespace std;

long long res, ans;

vector<int> a;
vector<long long> sum;
vector<vector<int>> g;

void dfs(int v, int p = -1, int h = 0) {
	res += h * 1ll * a[v];
	sum[v] = a[v];
	
	for (auto to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs(to, v, h + 1);
		sum[v] += sum[to];
	}
}

void go(int v, int p = -1) {
	ans = max(ans, res);
	
	for (auto to : g[v]) {
		if (to == p) {
			continue;
		}
		
		res -= sum[to];
		sum[v] -= sum[to];
		res += sum[v];
		sum[to] += sum[v];
		
		go(to, v);
		
		sum[to] -= sum[v];
		res -= sum[v];
		sum[v] += sum[to];
		res += sum[to];
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	a = vector<int>(n);
	sum = vector<long long>(n);
	g = vector<vector<int>>(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs(0);
	go(0);
	
	cout << ans << endl;
	
	return 0;
}
