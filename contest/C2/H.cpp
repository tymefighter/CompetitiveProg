#include<iostream>
#include<vector>

using namespace std;

void solve(int n, char *s) {
    vector<int> blocks;

    char prevChar = s[0];
    int count = 1;

    for(int i = 1;i < n;i++) {
        if(s[i] == prevChar)
            count ++;
        else {
            prevChar = s[i];
            blocks.push_back(count);
            count = 1;
        }
    }
    blocks.push_back(count);

    long long ans = (((long long) n) * (n - 1)) / 2;

    if(blocks.size() == 1) {
        printf("%lld\n", ans);
        return;
    }

    ans -= blocks[0] + blocks[static_cast<int>(blocks.size()) - 1] - 1;
    for(int i = 1;i < static_cast<int>(blocks.size()) - 1;i++)
        ans -= 2 * blocks[i] - 1;

    printf("%lld\n", ans);
}

int main() {
    int n;
    char *s;
    scanf("%d ", &n);
    s = new char[n + 1];
    scanf("%s ", s);
    solve(n, s);
    delete [] s;
    return 0;
}