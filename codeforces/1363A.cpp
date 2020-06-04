#include<iostream>

using namespace std;

int n, x;
int o, e;

void readInput() {
    cin >> n >> x;

    o = e = 0;
    for(int i = 0;i < n;i++) {
        int u;
        cin >> u;

        if(u % 2 == 1)
            o ++;
        else
            e ++;
    }
}

bool solve() {
    if(o == 0)
        return false;

    o --;
    x --;

    if(x == 0)
        return true;
    
    if(e > 0) {

        if(e >= x)
            return true;

        x -= e;
        if(x % 2 == 1) // remove one even
            x ++;
    }

    if(x % 2 == 0 && 2 * (o / 2) >= x) // use all odds
        return true;

    return false;
}

int main() {
    int t;
    cin >> t;

    while(t --) {
        readInput();
        if(solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}