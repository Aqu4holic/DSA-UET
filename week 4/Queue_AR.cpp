//author: blackwhite
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

inline void io(char *u, string filename){
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

const int N = 2e5 + 5;
struct Queue{
	int cur = 0, sz = 0;
	int mem[N];

	Queue(){
		sz = cur = 0;
		memset(mem, 0, sizeof(mem));
	}

	bool empty(){
		return (cur - 1 == sz);
	}

	int size(){
		return (!sz ?  0 : sz - cur + 1);
	}

	int front(){
		if (empty()){
			return -1;
		}

		return mem[cur];
	}

	void enqueue(int x){
		mem[++sz] = x;

		cur = (sz == 1 ? 1 : cur);
	}

	void dequeue(){
		if (empty()){
			return;
		}

		mem[cur++] = 0;

		if (empty()){
			cur = sz = 0;
		}
	}
};

void solve(){
	int n;
	cin >> n;
	string type;
	Queue q;
	for (int i = 1, x; i <= n; ++i){
		cin >> type;

		if (type[0] == 'e'){
			cin >> x;

			q.enqueue(x);
		}
		else{
			q.dequeue();
		}
	}

	for (; q.size(); q.dequeue()){
		cerr << q.front() <<' ';
	}
	cout << el;
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