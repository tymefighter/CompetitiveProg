#include<iostream>
#include<algorithm>

using namespace std;

int n;
string p[55];

void read() {
    cin >> n;

    for(int i = 0;i < n;i++)
        cin >> p[i];
}

void solve() {

    vector<int> idx(n, 0);

    while(true) {

        
    }
}

int main() {

    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        read();
        if(!solve(i))
            printf("Case #%d: *\n", i);
    }

    return 0;
}