#include<iostream>
#include<vector>

using namespace std;

void build_z_function(const string &s, vector<int> &z) {
    int n = s.size();
    int l = 0, r = 0;
    z.clear();
    z.resize(n);

    z[0] = -1;  // undefined
    for(int i = 1;i < n;i++) {
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while(i + z[i] <= n && s[z[i]] == s[i + z[i]])
            z[i] ++;

        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int main() {

    string s;
    vector<int> z;

    cin >> s;
    
    build_z_function(s, z);

    for(int val : z)
        cout << val << " ";
    cout << "\n";

    return 0;
}