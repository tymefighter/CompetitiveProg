#include<iostream>

using namespace std;

long long a[551][551];
void build_table() {

    for(int i = 0;i <= 550;i++) {
        a[i][0] = a[i][i] = 1;
        for(int j = 1;j <= i - 1;j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }

}

int n;

void solve() {
    int i = 0, j = 0;
    long long pw = 1, sum_val = 0;

    long long ct = 0;

    while(true) {

        if(sum_val + pw >= n)
            break;
        
        sum_val += pw;
        pw = (pw << 1);

        if(j == -1) {
            if(sum_val + pw >= n) {
                j = 0;
                for(;j <= i;j++) {
                    cout << i + 1 << " " << j + 1 << "\n";

                    if(sum_val + a[i + 1][j + 1] <= n) {
                        cout << i + 2 << " " << j + 2 << "\n";
                        sum_val += a[i + 1][j + 1];
                    }
                }
            }
            else {
                j = 0;
                for(;j <= i;j++) {
                    cout << i + 1 << " " << j + 1 << "\n";
                }
            }
        }
        else {
            if(sum_val + pw >= n) {
                for(;j >= 0;j--) {
                    cout << i + 1 << " " << j + 1 << "\n";

                    if(sum_val + a[i + 1][j] <= n) {
                        cout << i + 2 << " " << j + 1 << "\n";
                        sum_val += a[i + 1][j];
                    }
                }
            }
            else {
                for(;j >= 0;j--)
                    cout << i + 1 << " " << j + 1 << "\n";
            }
        }

        i ++;
    }

    if(j == 0) {
        while(sum_val < n) {
            cout << i + 1 << " 1\n";
            i ++;
            sum_val ++;
        }
    }
    else {
        while(sum_val < n) {
            cout << i + 1 << " " << j + 1 << "\n";
            i ++;
            j ++;
            sum_val ++;
        }
    }
}

int main() {

    build_table();

    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        cin >> n;
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}