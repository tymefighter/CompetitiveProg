#include<iostream>
#include<vector>

using namespace std;

const int N = 1005;
int n, a[N];

void readInput() {
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
}

bool b[N];

int mex() {
    for(int i = 0;i <= n;i++)
        b[i] = false;

    for(int i = 1;i <= n;i++)
        b[a[i]] = true;

    for(int i = 0;i <= n;i++) {
        if(!b[i])
            return i;
    }

    return 0;
}

int notInOrder() {
    for(int i = 1;i <= n;i++) {
        if(a[i] != i)
            return i;
    }

    return -1;
}

void solve() {
    vector<int> ans;

    int mexVal = mex();
    while(mexVal != 0) {
        ans.push_back(mexVal);
        a[mexVal] = mexVal;
        mexVal = mex();
    }

    int idx = notInOrder();
    while(idx != -1) {
        ans.push_back(idx);
        a[idx] = 0;

        mexVal = mex();
        while(mexVal != 0) {
            ans.push_back(mexVal);
            a[mexVal] = mexVal;
            mexVal = mex();
        }
        idx = notInOrder();
    }

    cout << ans.size() << "\n";
    for(int x : ans)
        cout << x << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        readInput();
        solve();
    }
    return 0;
}