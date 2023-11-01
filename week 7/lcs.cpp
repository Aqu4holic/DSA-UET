// author: blackwhite
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define fi first
#define se second
#define pb push_back
#define oo 1e18
#define eps 1e-9
#define el '\n'
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;

void io(char *u, string filename){
	int x = u[0] - '0';
	if (x < 0 || x > 9){
		return;
	}
	if (!x){
		freopen((filename + ".inp").c_str(), "r", stdin);
		return;
	}
	if (x == 1){
		freopen((filename + ".inp").c_str(), "r", stdin);
		freopen((filename + ".out").c_str(), "w", stdout);
		return;
	}
	if (x == 2){
		freopen((filename + ".inp").c_str(), "r", stdin);
		freopen((filename + ".ans").c_str(), "w", stdout);
		return;
	}
	freopen((filename + ".out").c_str(), "w", stdout);
}

int n, m;
vi a, b;
vector <vi> dp;

void solve(){
	cin >> n >> m;
	a.assign(n + 5, 0);
	b.assign(m + 5, 0);
	vector <vi> dp(n + 5, vi(m + 5, 0));

	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i){
		cin >> b[i];
	}

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			if (a[i] == b[j]){
				dp[i][j] = max({dp[i - 1][j - 1] + 1, dp[i][j]});
			}
			else{
				dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
			}
		}
	}

	cout << dp[n][m] << el;
}

signed main(signed argv, char *args[]){
	cin.tie(0) -> sync_with_stdio(0);
	#ifdef blackwhite
	assert(argv > 1);
	io(args[1], "test");
	#endif

	int tc = 1;
	// cin >> tc;
	for (int tt = 1; tt <= tc; ++tt){
		solve();
	}
}