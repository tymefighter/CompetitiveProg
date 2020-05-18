#include<iostream>
#include<cmath>

using namespace std;

const int N = 1005;
int n;
long long d, a[N];

void readInput() {
    cin >> n >> d;

    for(int i = 0;i < n;i++)
        cin >> a[i];
}

bool checkDay(long long day) {

    for(int i = 0;i < n;i++) {
        day = a[i] * static_cast<long long>(ceil(day / static_cast<double>(a[i])));
    }

    return day <= d;
}

long long solve() {

    long long low = 0, high = d, mid, ans = -1;

    while(low <= high) {
        mid = (low + high) >> 1;

        if(checkDay(mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
}

int main() {

    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        readInput();
        printf("Case #%d: %lld\n", i, solve());
    }

    return 0;
}