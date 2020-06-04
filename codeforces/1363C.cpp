#include<iostream>

using namespace std;

const int N = 1005;
int n, x, deg[N];

void readInput() {
    cin >> n >> x;
    x --;

    for(int i = 0;i < n;i++)
        deg[i] = 0;

    for(int i = 0;i < n - 1;i++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        deg[u] ++;
        deg[v] ++;
    }
}

inline bool solve() { return (n % 2 == 0) || (deg[x] <= 1);}

int main() {

    int t;
    cin >> t;
    while(t --) {
        readInput();
        if(solve())
            cout << "Ayush\n";
        else
            cout << "Ashish\n";
    }
    return 0;
}