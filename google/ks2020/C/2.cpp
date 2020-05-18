#include<iostream>
#include<vector>
#include<set>

using namespace std;

int n, m, numChar;
char a[35][35];
bool filled[35][35];
vector<char> ch;
set<char> placed;

void readInput() {
    scanf("%d %d", &n, &m);

    set<char> s;
    ch.clear();
    placed.clear();

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
            filled[i][j] = false;
            s.insert(a[i][j]);
        }
    }

    for(int j = 0;j < m;j++) {
        for(int i = 0;i < n / 2;i++)
            swap(a[i][j], a[n - i - 1][j]);
    }

    for(char c : s)
        ch.push_back(c);

    numChar = ch.size();
}

bool can_be_placed(char c) {
    for(int i = 1;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(a[i][j] == c) {
                if(a[i - 1][j] != c && !filled[i - 1][j])
                    return false;
            }
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(a[i][j] == c)
                filled[i][j] = true;
        }
    }

    placed.insert(c);
    return true;
}

void solve() {
    bool placed_char = true;
    vector<char> seq;

    while(placed_char) {
        placed_char = false;
        for(char c : ch) {
            if(placed.find(c) != placed.end())
                continue;

            if(can_be_placed(c)) {
                placed_char = true;
                seq.push_back(c);
            }
        }
    }

    if(placed.size() != ch.size()) {
        printf("-1\n");
        return;
    }

    for(char c : seq)
        printf("%c", c);
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1;i <= t;i++) {
        readInput();
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}