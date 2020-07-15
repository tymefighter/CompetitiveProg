#include<iostream>
#include<vector>

using namespace std;

void compute_prefix(vector<int> &pi, const string &s) {
    int n = s.size();
    pi.clear();
    pi.resize(n);

    pi[0] = 0;
    for(int i = 1;i < n;i++) {
        int j = pi[i - 1];

        while(j > 0 && s[j] != s[i])
            j = pi[j - 1];

        if(s[j] == s[i])
            pi[i] = j + 1;
        else
            pi[i] = 0;
    }
}

void solve(const string &s) {
    int l = s.size(), x = -1;
    vector<int> pi;
    string seq;

    compute_prefix(pi, s);

    for(int n = l / 3 + 1;n <= (l / 2);n++) {
        if(pi[2 * n - 1] >= n) {
            seq = s.substr(0, n);
            x = l - 2 * n;
            break;
        }
    }

    for(int i = 0;i < 8;i++)
        cout << seq[(x + i) % seq.size()];

    cout << "...\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}