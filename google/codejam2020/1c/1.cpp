#include<iostream>

using namespace std;

int x, y;
string a;

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int solve() {

    if(x == 0 && y == 0)
        return 0;

    for(int i = 0;i < a.size();i++) {
        if(a[i] == 'N')
            y ++;
        else if(a[i] == 'E')
            x ++;
        else if(a[i] == 'S')
            y --;
        else if(a[i] == 'W')
            x --;

        if(dist(0, 0, x, y) <= i + 1)
            return i + 1;
    }

    return -1;
}

int main() {

    int t;
    cin >> t;

    for(int i = 1;i <= t;i++) {
        cin >> x >> y;
        cin >> a;
        int ans = solve();

        if(ans == -1)
            printf("Case #%d: IMPOSSIBLE\n", i);
        else
            printf("Case #%d: %d\n", i, ans);
    }

    return 0;
}