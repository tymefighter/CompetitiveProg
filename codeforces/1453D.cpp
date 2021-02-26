#include <iostream>
#include <vector>

using namespace std;

const long long MAX_K = 100000000000000000;
vector<pair<int, long long> > seq;

void generateSeq() {
    int i = 1;
    long long x = 2;

    while(x <= MAX_K) {
        seq.push_back({i, x});
        i ++;
        x = 2 * (x + 1);
    }
}

void solve(long long k) {

    if(k & 1) {
        printf("-1\n");
        return;
    }

    int idx = seq.size() - 1;

    vector<int> ans;

    while(k > 0 && idx >= 0) {
        if(seq[idx].second > k)
            idx --;
        else {
            k -= seq[idx].second;

            ans.push_back(1);
            for(int i = 1;i < seq[idx].first;i++) ans.push_back(0);
        }
    }

    printf("%lu\n", ans.size());
    for(int x : ans) printf("%d ", x);
    printf("\n");
}

int main() {

    generateSeq();

    int t;
    scanf("%d ", &t);

    while(t --) {
        long long k;
        scanf("%lld ", &k);
        solve(k);
    }

    return 0;
}
