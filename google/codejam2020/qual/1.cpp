#include<iostream>
#include<unordered_set>

using namespace std;

const int N = 105;
int n, a[N][N];
long long trace;

void read() {
    
    scanf("%d", &n);
    trace = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            scanf("%d", &a[i][j]);
        }

        trace += a[i][i];
    }
}

unordered_set<int> s;
bool checkRow(int r) {
    
    s.clear();
    for(int j = 0;j < n;j++) {
        if(s.find(a[r][j]) != s.end())  // Repeated element found
            return true;
        
        s.insert(a[r][j]);
    }

    return false;
}

bool checkCol(int c) {
    
    s.clear();
    for(int i = 0;i < n;i++) {
        if(s.find(a[i][c]) != s.end())  // Repeated element found
            return true;
        
        s.insert(a[i][c]);
    }

    return false;
}

void solve(int case_num) {

    int ans_row = 0, ans_col = 0;
    for(int r = 0;r < n;r++)
        ans_row += static_cast<int>(checkRow(r));

    for(int c = 0;c < n;c++)
        ans_col += static_cast<int>(checkCol(c));

    printf("Case #%d: %lld %d %d\n", case_num, trace, ans_row, ans_col);
}

int main() {

    int t;
    scanf("%d", &t);
    for(int i = 1;i <= t;i++) {
        read();
        solve(i);
    }
    return 0;
}