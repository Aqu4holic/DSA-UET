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

struct student{
	string id, name, clss;

	student(){
		id = name = clss = "NA";
	}

	student(string _id, string _name, string _clss){
		id = _id;
		name = _name;
		clss = _clss;
	}

	string get_info(){
		return name + ',' + clss;
	}
};

student parse(string x, int i = 0, int type = 1){
	student res("", "", "");

	for (; x[i] != ',' && i < sz(x) - 1; ++i){
		res.id += x[i];
	}

	if (type){
		++i;
		for (; x[i] != ',' && i < sz(x) - 1; ++i){
			res.name += x[i];
		}

		++i;
		for (; x[i] != ',' && i < sz(x) - 1; ++i){
			res.clss += x[i];
		}
	}
	else{
		res.name = res.clss = "NA";
	}

	return res;
}

void solve(){
	map <string, student> a;
	for (string x; cin >> x;){
		student tmp;

		if (x[0] == 'I'){
			if (x[2] == 's'){
				tmp = parse(x, 6);
				if (!a.count(tmp.id)){
					a[tmp.id] = tmp;
				}
			}
			else{
				tmp = parse(x, 5, 0);

				if (a.count(tmp.id)){
					cout << a[tmp.id].get_info() << el;
				}
				else{
					cout << tmp.get_info() << el;
				}
			}
		}
		else{
			tmp = parse(x, 6, 0);

			if (a.count(tmp.id)){
				a.erase(tmp.id);
			}
		}
	}
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