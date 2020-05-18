#include<iostream>
#include<algorithm>

using namespace std;

int n, d;
long long a[305];

void readInput() {
    cin >> n >> d;
    for(int i = 0;i < n;i++)
        cin >> a[i];
}

int solve() {
    if(n == 1)
        return d - 1;
    else if(n == 2) {
        long long min_val = min(a[0], a[1]);
        long long max_val = max(a[0], a[1]);

        if(d == 2)
            return (min_val == max_val ? 0 : 1);
        else {
            
            if(max_val % 2 == 0 && min_val == max_val / 2)
                return 1;
            else
                return 2;
        } 
    }
    else {
        sort(a, a + n);

        if(d == 2) {
            int count = 1;
            for(int i = 1;i < n;i++) {
                if(a[i] == a[i - 1])
                    count ++;
                else {
                    if(count >= 2)
                        return 0;
                    count = 1;
                }
            }
            if(count >= 2)
                return 0;

            return 1;
        }
        else {
            bool ans_one = false;

            int count = 1;
            for(int i = 1;i < n;i++) {
                if(a[i] == a[i - 1])
                    count ++;
                else {
                    if(count >= 3)
                        return 0;
                    else if(count >= 2)
                        ans_one = true;
                    count = 1;
                }
            }
            if(count >= 3)
                return 0;
            else if(ans_one)
                return 1;

            for(int i = 0;i < n;i++) {
                for(int j = 1;j < n;j++) {
                    if(a[j] % 2 == 0 && a[i] == a[j] / 2)
                        return 1;
                }
            }

            return 2;
        }
    }
}

int main() {

    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        readInput();
        if(d > 3)
            continue;

        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}