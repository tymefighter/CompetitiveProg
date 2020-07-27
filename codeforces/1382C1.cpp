#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 100005;
int n;
bool a[N], b[N];

void read() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++) {
        char c;
        scanf("%c ", &c);
        a[i] = (c == '1');
    }
    for(int i = 0;i < n;i++) {
        char c;
        scanf("%c ", &c);
        b[i] = (c == '1');
    }
}

void operation(int len) {
    for(int i = 0;i < len;i++)
        a[i] = !a[i];

    reverse(a, a + len);
}

void solve() {
    vector<int> ans;
    for(int i = n - 1;i > 0;i--) {
        if(a[i] != b[i]) {
            if(a[0] == a[i]) {
                operation(i + 1);
                ans.push_back(i + 1);
            }
            else {
                operation(1);
                ans.push_back(1);
                operation(i + 1);
                ans.push_back(i + 1);
            }
        }
    }

    if(a[0] != b[0])
        ans.push_back(1);

    printf("%d ", static_cast<int>(ans.size()));
    for(int idx : ans)
        printf("%d ", idx);
    printf("\n");
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        read();
        solve();
    }
    return 0;
}