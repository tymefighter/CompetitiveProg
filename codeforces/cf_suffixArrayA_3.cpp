#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 300005;

string t, s;
int n, p[N], c[N];

pair<char, int> a[N];
int cnt[N], pos[N];
int pNew[N], cNew[N];

void readInput() {
    cin >> t;
    t += '#';
    n = t.size();
}

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
        a[i] = {t[i], i};
    
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
            pair<int, int> curr = {c[p[i]], c[(p[i] + (1 << k) % n)]};
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

bool binarySearch() {
    int m = s.size();
    if(m > n)
        return false;

    int low = 1, high = n;

    while(low <= high) {
        int mid = (low + high) >> 1;
        string u = t.substr(p[mid], min(n - p[mid], m));

        if(u == s)
            return true;
        else if(u < s)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

void solve() {
    suffixArray();
    t.pop_back();
    n --;

    int q;
    cin >> q;

    while(q --) {
        cin >> s;
        if(binarySearch())
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main() {
    readInput();
    solve();
    return 0;
}