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

namespace knapsack_greedy{
	struct item{
		int w = 0, v = 0;

		bool operator < (const item &o) const{
			// v / w > o.v / o.w;

			return (v * o.w > o.v * w);
		}
	};

	void solve(){
		int n, w;
		cin >> n >> w;
		vector <item> a(n + 5);
		for (int i = 1; i <= n; ++i){
			cin >> a[i].w >> a[i].v;
		}

		sort(a.begin() + 1, a.begin() + n + 1);

		int res = 0;
		for (int i = 1; i <= n && w > 0; ++i){
			if (a[i].w <= w){
				w -= a[i].w;

				res += a[i].v;
			}
		}

		cout << res << el;
	}
}

namespace knapsack_dp{
	struct item{
		int w = 0, v = 0;

		bool operator < (const item &o) const{
			// v / w > o.v / o.w;

			return (v * o.w > o.v * w);
		}
	};

	void solve(){
		int n, w;
		cin >> n >> w;
		vector <item> a(n + 5);
		vector <vi> dp(n + 5, vi(w + 5, 0));
		for (int i = 1; i <= n; ++i){
			cin >> a[i].w >> a[i].v;
		}

		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= w; ++j){
				if (j >= a[i].w){
					dp[i][j] = max({dp[i][j], dp[i - 1][j - a[i].w] + a[i].v, dp[i - 1][j]});
				}
				else{
					dp[i][j] = max({dp[i][j], dp[i - 1][j]});
				}
			}
		}

		cout << dp[n][w] << el;
	}
}

void solve(){
	// knapsack_greedy::solve();
	knapsack_dp::solve();

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