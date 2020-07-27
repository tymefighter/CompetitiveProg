#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10005;
string s;
int n, p[N], c[N];

void readInput() {
    cin >> s;
    s += '$';
    n = s.size();
}

pair<char, int> b[N];
pair<pair<int, int>, int> a[N];

void suffixArray() {
    // k = 0
    for(int i = 0;i < n;i++)
        b[i] = {s[i], i};
    
    sort(b, b + n);
    p[0] = b[0].second;
    c[p[0]] = 0;
    for(int i = 1;i < n;i++) {
        p[i] = b[i].second;
        if(b[i].first == b[i - 1].first)
            c[p[i]] = c[p[i - 1]];
        else
            c[p[i]] = c[p[i - 1]] + 1;
    }

    // k -> k + 1
    int k = 0;
    while((1 << k) < n) {
        for(int i = 0;i < n;i++)
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};

        sort(a, a + n);
        p[0] = a->second;
        c[p[0]] = 0;

        for(int i = 1;i < n;i++) {
            p[i] = a[i].second;
            if(a[i].first == a[i - 1].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }

        k ++;
    }
}

int main() {

    readInput();
    suffixArray();
    for(int i = 0;i < n;i++)
        cout << s.substr(p[i], n - p[i]) << "\n";

    return 0;
}
