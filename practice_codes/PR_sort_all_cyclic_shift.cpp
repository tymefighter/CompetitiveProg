#include<iostream>
#include<vector>

using namespace std;

const int NUM_CHAR = 256;

inline int char2int(char c) {return static_cast<unsigned>(c);}

vector<int> sortAllCyclicShift(const string &s) {
    int n = s.size();
    vector<int> p(n), c(n);

    // Initialize (k = 0)
    vector<int> cnt(NUM_CHAR, 0);
    for(int i = 0;i < n;i++)
        cnt[char2int(s[i])] ++;

    for(int i = 1;i < NUM_CHAR;i++)
        cnt[i] += cnt[i - 1];

    for(int i = n - 1;i >= 0;i--)
        p[-- cnt[char2int(s[i])]] = i;

    int numClasses = 1;
    c[p[0]] = 0;
    for(int i = 1;i < n;i++) {
        if(s[p[i]] == s[p[i - 1]])
            c[p[i]] = c[p[i - 1]];
        else {
            numClasses ++;
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    // Iteration (forall 0 < k <= floor(logn) + 1)
    // h = k - 1

    for(int h = 0;(1 << h) < n;h++) {
        vector<int> pn(n), cn(n);
        
        for(int i = 0;i < n;i++) {
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0)
                pn[i] += n;
        }

        vector<int> cnt(numClasses, 0);

        for(int i = 0;i < n;i++)
            cnt[c[i]] ++;

        for(int i = 1;i < numClasses;i++)
            cnt[i] += cnt[i - 1];
        
        for(int i = n - 1;i >= 0;i--)
            p[-- cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        numClasses = 1;
        for(int i = 0;i < n;i++) {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            pair<int, int> curr = {c[p[i]], c[(p[i] + (1 << h)) % n]};

            if(curr == prev)
                cn[p[i]] = cn[p[i - 1]];
            else {
                numClasses ++;
                cn[p[i]] = cn[p[i - 1]] + 1;
            }
        }

        c = cn;
    }

    return p;
}

int main() {

    string s;
    cin >> s;

    vector<int> p = sortAllCyclicShift(s);

    for(int idx : p)
        cout << idx << "\n";

    return 0;
}