#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

const int N = 300005;
const long long MOD = 998244353;

int n, k;
pair<int, int> seg[N];
map<int, int> begin_, cont;

void readInput() {
    scanf("%d %d ", &n, &k);

    begin_.clear();
    cont.clear();

    for(int i = 0;i < n;i++) {
        scanf("%d %d ", &seg[i].first, &seg[i].second);
        begin_[seg[i].first] ++;
    }
}

long long binaryExp(long long x, long long m, long long mod) {
    if(m == 0)
        return 1;
    else if(m % 2 == 1)
        return (x * binaryExp(x, m - 1, mod)) % mod;
    else {
        long long val = binaryExp(x, m / 2, mod);
        return (val * val) % mod;
    }
}

long long coeff[N + 1];

void computeBinomialCoeff() {
    for(int i = 0;i < k;i++)
        coeff[i] = 0;

    coeff[k] = 1;

    for(int i = k + 1;i <= n;i++) {
        long long val = (coeff[i - 1] * i) % MOD;
        val = (val * binaryExp(i - k, MOD - 2, MOD)) % MOD;
        coeff[i] = val;
    }
}

void computeVal() {
    vector<pair<int, int> > pre_seg;
    for(int i = 0;i < n;i++) {
        pre_seg.push_back({seg[i].first, 1});
        pre_seg.push_back({seg[i].second + 1, -1});
    }

    sort(pre_seg.begin(), pre_seg.end());

    for(int i = 1;i < pre_seg.size();i++)
        pre_seg[i].second += pre_seg[i - 1].second;

    for(int i = 0;i < n;i++) {
        int l = seg[i].first;

        int low = 0, high = static_cast<int>(pre_seg.size()) - 1;
        int ansIdx = -1;

        while(low <= high) {
            int mid = (low + high) >> 1;
            
            if(pre_seg[mid].first <= l) {
                ansIdx = max(ansIdx, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        cont[l] = (ansIdx == -1 ? 0 : pre_seg[ansIdx].second);
    }
}

void solve() {
    computeBinomialCoeff();
    computeVal();

    long long ans = 0;
    for(pair<int, int> s : begin_) {
        int l = s.first;

        ans = (ans + coeff[cont[l]]) % MOD;
        ans = (ans - coeff[cont[l] - begin_[l]]) % MOD;
    }

    if(ans < 0)
        ans += MOD;
    
    printf("%lld\n", ans);
}

int main() {

    readInput();
    solve();

    return 0;
}
