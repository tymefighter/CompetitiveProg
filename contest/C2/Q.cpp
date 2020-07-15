#include<iostream>
#include<vector>

using namespace std;

void computeZ(const string &s, vector<int> &z) {
    int n = s.size(), l = -1, r = -1;
    z.clear();
    z.resize(n);
    z[0] = -1;

    for(int i = 1;i < n;i++) {
        if(i > r)
            z[i] = 0;
        else
            z[i] = min(r - i + 1, z[i - l]);

        while(i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i] ++;

        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

void solve() {
    string a, b, s;
    vector<int> z, ans;

    cin >> a >> b;
    s = b + "#" + a;

    computeZ(s, z);

    for(int i = b.size() + 1;i < s.size();i++) {
        if(z[i] == b.size())
            ans.push_back(i - static_cast<int>(b.size()));
    }

    if(ans.size() == 0)
        cout << "Not Found\n";
    else {
        cout << ans.size() << "\n";
        for(int idx : ans)
            cout << idx << " ";
        cout << "\n";
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t --)
        solve();

    return 0;
}