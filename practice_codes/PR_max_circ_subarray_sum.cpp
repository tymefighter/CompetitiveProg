#include<iostream>
#include<vector>

using namespace std;

const long long INF = static_cast<long long>(1e15);

void readInput(vector<int> &a) {
    int n;
    cin >> n;
    a.clear();
    a.resize(n);

    for(int i = 0;i < n;i++)
        cin >> a[i];
}

long long kadaneAlgo(const vector<int> &a) {
    long long max_sum = -INF, curr_sum = 0;

    for(int x : a) {
        if(curr_sum < 0)
            curr_sum = 0;

        curr_sum += x;
        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}

long long maxCircSubarraySum(const vector<int> &a) {
    long long maxSumNoWrap = kadaneAlgo(a), maxWithWrap = -INF;
    int n = a.size();
    vector<long long> prefix(n), max_prefix(n), suffix(n), max_suffix(n);

    for(int i = 0;i < n;i++) {
        prefix[i] = (i > 0 ? prefix[i - 1] : 0) + a[i];
        max_prefix[i] = (i > 0 ? max(max_prefix[i - 1], prefix[i]) : prefix[i]);
    }

    for(int i = n - 1;i >= 0;i--) {
        suffix[i] = (i < n - 1 ? suffix[i + 1] : 0) + a[i];
        max_suffix[i] = (i < n - 1 ? max(max_suffix[i + 1], suffix[i]) : suffix[i]);
    }

    for(int i = 1;i < n - 1;i++) {
        maxWithWrap = max(maxWithWrap, max_prefix[i - 1] + max_suffix[i + 1]);
    }

    return max(maxSumNoWrap, maxWithWrap);
}

int main() {

    int t;
    vector<int> a;
    cin >> t;
    while(t--) {
        readInput(a);
        cout << maxCircSubarraySum(a) << "\n";
    }

    return 0;
}