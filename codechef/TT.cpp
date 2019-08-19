#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <vector>
#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <random>
#include <time.h>
#include <cassert>
// #include <multiset>

#define prev askdnsajd
#define rank asasdmdnasd
#define next lsjndajbs
#define hash asmdklansd
#define index asdklnas
#define right sld
#define left sldl
using namespace std;

typedef long long ll;
typedef long double dbl;

template<class T>
void print(vector<T> s){
	for (T x : s)
		cout << x << " ";
	cout << endl;
}


void solve(){
	int n, d;
	cin >> n >> d;
	vector<ll> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s.begin(), s.end());
	vector<ll> pref(n + 1, 0);
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + s[i];
	ll l = 0;
	ll r = 1e9 + 1;
	while (l + 1 < r){
		ll m = (l + r) / 2;
		if (s[n - 1] < m){
			r = m;
			continue;
		}
		ll pos = lower_bound(s.begin(), s.end(), m) - s.begin();
		ll summa = pref[n] - pref[pos] - (ll)(m - 1) * (ll)(n - pos);
		if (summa > d)
			l = m;
		else
			r = m;
	}
	ll maxi = l;
	l = 0, r = 1e9 + 1;
	while (l + 1 < r){
		ll m = (l + r) / 2;
		if (s[0] > m){
			l = m;
			continue;
		}
		ll pos = lower_bound(s.begin(), s.end(), m) - s.begin();
		if ((ll)m * pos - pref[pos] <= d)
			l = m;
		else
			r = m;
	}
	if (maxi >= l){
		cout << maxi - l << "\n";
		return;
	}
	if (pref[n] % n != 0)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	int t;
	cin >> t;
	while (t-- > 0){
		solve();
	}
	return 0;	
}	