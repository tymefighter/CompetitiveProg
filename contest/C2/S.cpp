#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

map<char, int> char2pos;
string a, w, s;

void readInput() {
    cin >> a;
    cin >> w;
    cin >> s;
    char2pos.clear();
    for(int i = 0;i < a.size();i++)
        char2pos[a[i]] = i;
}

char nextChar(char c) {
    return a[(char2pos[c] + 1) % static_cast<int>(a.size())];
}

void cyclicShift() {
    for(int i = 0;i < s.size();i++)
        s[i] = nextChar(s[i]);
}

void computeZ(const string &u, vector<int> &z) {
    z.clear();
    z.resize(u.size());

    z[0] = -1;
    int l = -1, r = -1;

    for(int i = 1;i < z.size();i++) {
        if(i > r)
            z[i] = 0;
        else
            z[i] = min(z[i - l], r - i + 1);
        
        while(i + z[i] < u.size() && u[i + z[i]] == u[z[i]])
            z[i] ++;

        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

bool checkSatisfy() {
    string u = w + "#" + s;
    vector<int> z;
    computeZ(u, z);

    int numOcc = 0;
    for(int i = w.size() + 1;i < u.size();i++)
        numOcc += (z[i] == w.size() ? 1 : 0);

    return numOcc == 1;
}

void solve() {
    vector<int> ans;
    bool zeroSat = checkSatisfy();

    for(int i = 1;i < a.size();i++) {
        cyclicShift();
        if(checkSatisfy())
            ans.push_back(static_cast<int>(a.size()) - i);
    }
    if(zeroSat)
        ans.push_back(0);

    reverse(ans.begin(), ans.end());

    if(ans.size() == 0)
        cout << "no solution\n";
    else if(ans.size() == 1)
        cout << "unique: " << ans[0] << "\n";
    else {
        cout << "ambiguous: ";

        for(int i = 0;i < ans.size();i++) {
            if(i)
                cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
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