#include<iostream>
#include<vector>
#include<map>

using namespace std;

const int N = 26;
int n, k;
int a[N];
long long S;

void readInput() {
    scanf("%d %d %lld ", &n, &k, &S);
    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);
}

long long fact[19];

void precomputeFact() {
    fact[0] = fact[1] = 1;
    for(int i = 2;i <= 18;i++)
        fact[i] = fact[i - 1] * i;
}

vector<long long> sumLeft[N];
map<long long, int> countRight[N];

void resetDS() {
    for(int i = 0;i <= k;i++) {
        sumLeft[i].clear();
        countRight[i].clear();
    }
}

void takeLeft(int mask, int submask) {
    long long sumVal = 0;
    int numGivenFactorial = 0;
    bool cannotTake = false;

    for(int i = 0;(1 << i) <= mask;i++) {
        if(mask & (1 << i)) {
            if(submask & (1 << i)) {
                numGivenFactorial ++;
                if(numGivenFactorial > k || a[i] > 18) {
                    cannotTake = true;
                    break;
                }

                sumVal += fact[a[i]];
            }
            else
                sumVal += a[i];

            if(sumVal > S) {
                cannotTake = true;
                break;
            }
        }
    }

    if(!cannotTake)
        sumLeft[numGivenFactorial].push_back(sumVal);
}

void buildLeft() {
    int m = n / 2;
    for(int mask = 0;mask < (1 << m);mask ++) {
        int submask = mask;
        while(submask) {
            takeLeft(mask, submask);
            submask = (submask - 1) & mask;
        }
        takeLeft(mask, submask);
    }
}

void takeRight(const vector<int> &b, int mask, int submask) {
    long long sumVal = 0;
    int numGivenFactorial = 0;
    bool cannotTake = false;

    for(int i = 0;(1 << i) <= mask;i++) {
        if(mask & (1 << i)) {
            if(submask & (1 << i)) {
                numGivenFactorial ++;
                if(numGivenFactorial > k || b[i] > 18) {
                    cannotTake = true;
                    break;
                }

                sumVal += fact[b[i]];
            }
            else
                sumVal += b[i];

            if(sumVal > S) {
                cannotTake = true;
                break;
            }
        }
    }

    if(!cannotTake)
        countRight[numGivenFactorial][sumVal] ++;
}

void buildRight() {
    int m = n / 2;
    vector<int> b(n - m);

    for(int i = m;i < n;i++)
        b[i - m] = a[i];

    m = n - m;

    for(int mask = 0;mask < (1 << m);mask ++) {
        int submask = mask;
        while(submask) {
            takeRight(b, mask, submask);
            submask = (submask - 1) & mask;
        }
        takeRight(b, mask, submask);
    }
}

void solve() {
    precomputeFact();
    resetDS();
    buildLeft();
    buildRight();

    long long ans = 0;

    for(int i = 0;i <= k;i++) {
        for(long long x : sumLeft[i]) {
            x = S - x;

            for(int j = 0;j <= k - i;j++) {
                if(countRight[j].find(x) != countRight[j].end())
                    ans += countRight[j][x];
            }
        }
    }

    printf("%lld\n", ans);
}

int main() {

    readInput();
    solve();

    return 0;
}
