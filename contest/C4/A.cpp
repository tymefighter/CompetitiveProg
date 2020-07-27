#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const int N = 605;

int n, l, m;
string u, v, s;

pair<char, int> a[N];
int p[N], c[N], pNew[N], cNew[N];
int cnt[N], pos[N], lcp[N];

void countingSort() {
    for(int i = 0;i < n;i++)
        cnt[i] = 0;

    for(int i = 0;i < n;i++)
        cnt[c[i]] ++;

    pos[0] = 0;
    for(int i = 1;i < n;i++)
        pos[i] = pos[i - 1] + cnt[i - 1];

    for(int i = 0;i < n;i++) {
        int x = c[p[i]];
        pNew[pos[x]] = p[i];
        pos[x] ++;
    }

    for(int i = 0;i < n;i++)
        p[i] = pNew[i];
}

void suffixArray() {
    for(int i = 0;i < n;i++)
        a[i] = {s[i], i};

    sort(a, a + n);
    p[0] = a[0].second;
    c[p[0]] = 0;
    for(int i = 1;i < n;i++) {
        p[i] = a[i].second;
        if(a[i].first == a[i - 1].first)
            c[p[i]] = c[p[i - 1]];
        else
            c[p[i]] = c[p[i - 1]] + 1;
    }

    int k = 0;
    while((1 << k) < n) {
        for(int i = 0;i < n;i++) {
            p[i] = (p[i] - (1 << k)) % n;
            if(p[i] < 0)
                p[i] += n;
        }

        countingSort();

        cNew[p[0]] = 0;
        for(int i = 1;i < n;i++) {
            pair<int, int> curr = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};

            if(curr == prev)
                cNew[p[i]] = cNew[p[i - 1]];
            else
                cNew[p[i]] = cNew[p[i - 1]] + 1;
        }

        for(int i = 0;i < n;i++)
            c[i] = cNew[i];

        k ++;
    }
}

void lcpArray() {
    suffixArray();

    int k = 0;
    for(int i = 0;i < n - 1;i++) {
        int pos_i = c[i];
        int j = p[pos_i - 1];

        while(s[i + k] == s[j + k])
            k ++;

        lcp[pos_i] = k;
        k = max(k - 1, 0);
    }
    lcp[0] = -1;
}

void solve() {
    lcpArray();
    int maxLen = 0;

    for(int i = 1;i < n;i++) {
        if((p[i - 1] < l && p[i] > l) || (p[i - 1] > l && p[i] < l))
            maxLen = max(maxLen, lcp[i]);
    }

    if(maxLen == 0) {
        cout << "No common sequence.\n";
        return;
    }

    set<string> ans;

    for(int i = 1;i < n;i++) {
        if((p[i - 1] < l && p[i] > l) || (p[i - 1] > l && p[i] < l)) {
            if(maxLen == lcp[i])
                ans.insert(s.substr(p[i], lcp[i]));
        }
    }

    for(const string &x : ans)
        cout << x << "\n";
}

int main() {

    int ct = 0;
    while(cin >> u) {
        if(ct)
            cout << "\n";
        cin >> v;
        s = u + '#' + v + '$';
        n = s.size();
        l = u.size();
        m = v.size();

        solve();
        ct ++;
    }


    return 0;
}