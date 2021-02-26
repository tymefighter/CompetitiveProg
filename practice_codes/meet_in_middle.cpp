#include<iostream>
#include<vector>
#include<map>

using namespace std;

/*
    Get number of subsequences that add up to
    the given value
*/

void readInput(vector<long long> &a, long long &sumVal) {
    int n;
    cin >> n >> sumVal;

    a.clear();
    a.resize(n);

    for(int i = 0;i < n;i++)
        cin >> a[i];
}

void computeAllSubseqSums(
    const vector<long long> &a,
    vector<long long> &sums
) {
    int n = a.size();
    sums.clear();

    for(int mask = 0;mask < (1 << n);mask++) {
        long long s = 0;
        for(int i = 0;(1 << i) <= mask;i++) {
            if(mask & (1 << i))
                s += a[i];
        }
        sums.push_back(s);
    }
}

void computeNumberOfSubseq(
    const vector<long long> &a, 
    const long long &sumVal
) {
    int n = a.size();
    vector<long long> sumLeft, sumRight;

    computeAllSubseqSums(
        vector<long long>(a.begin(), a.begin() + (n / 2)),
        sumLeft
    );
    computeAllSubseqSums(
        vector<long long>(a.begin() + n / 2, a.end()),
        sumRight
    );

    map<long long, int> m;

    for(long long x : sumRight)
        m[x] ++;
    
    long long ct = 0;
    for(long long x : sumLeft) {
        x = sumVal - x;
        if(m.find(x) != m.end())
            ct += m[x];
    }

    cout << ct << "\n";
}

int main() {

    vector<long long> a;
    long long sumVal;

    readInput(a, sumVal);
    computeNumberOfSubseq(a, sumVal);

    return 0;
}
