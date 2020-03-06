#define BZ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;
 
const int INF = 1 << 30;
const int maxn = 100010;
 
struct Lib {
	int n, t, m;
	vi books;
	Lib () {}
	Lib (int _n, int _t, int _m) {
		n = _n;
		t = _t;
		m = _m;
	}
};
 
int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);
 
    int b, l, d;
    cin >> b >> l >> d;

    vi scores (b);
    for (int i = 0; i < b; i++) {
    	cin >> scores[i];
    }

    vector <Lib> a(l);

    for (int i = 0; i < l; i++) {
    	int n, t, m;
    	cin >> n >> t >> m;
    	a[i] = Lib(n, t, m);

    	vi tem (n);
    	for (int j = 0; j < n; j++) {
    		cin >> tem[j];
    	}
    	a[i].books = tem;

    	// Sorting in descending order on basis of scores.
    	sort (a[i].books.begin(), a[i].books.end(), [&] (int x, int y) {
    		return scores[x] > scores[y];
    	});
    }

    int cur = 0;
    set <int> used;
    vector <Lib> ans;
    vi vis(l);
    vi points (l);
    vector <set<int>> cur_books (l);

    ll final = 0;

    while (cur < d) {
    	for (int i = 0; i < l; i++) {
    		if (!vis[i]) {
    			int left = d - cur - a[i].t;
    			cur_books[i].clear();
    			int cp = 0;
    			points[i] = 0;
    			for (int j = 0; j < a[i].books.size() and left; j += a[i].m, left--) {
    				for (int k = 0; k < a[i].m and j + k < a[i].books.size(); k++) {
    					if (!used.count(a[i].books[j + k])) {
    						cur_books[i].insert (a[i].books[j + k]);
    						points[i] += scores[a[i].books[j + k]];
    					}
    				}
    			}
    		}
    	}
    	int id = -1;
    	double crit = 0;
    	for (int i = 0; i < l; i++) {
    		if (points[i] * 1.0 / a[i].t > crit) {
    			crit = points[i] * 1.0 / a[i].t;
    			id = i;
    		}
    	}

    	assert (id != -1);

    	used.insert (cur_books[id].begin(), cur_books[id].end());
    	Lib ins (id, cur_books[id].size(), -1);

    	for (auto el: cur_books[id]) {
    		ins.books.push_back (el);
    	}
    	final += points[id];
    	cur += a[id].t;
    	cerr << id << "\n";
    	ans.push_back (ins);
    }
    
    cout << ans.size() << "\n";

    for (auto ins : ans) {
    	cout << ins.n << " " << ins.t << "\n";
    	for (auto el: ins.books) {
    		cout << el << " ";
    	} cout << "\n";
    }

    cerr << final << "\n";
    

}