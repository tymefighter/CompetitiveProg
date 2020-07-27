#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10005;

string s;
int n, p[N], c[N];

pair<char, int> b[N];
pair<pair<int, int>, int> a[N];

void readInput() {
    cin >> s;
    s += '$';
    n = s.size();
}

int ct[N], pos[N];
pair<pair<int, int>, int> aSort[N];

void radixSort() {
    // Sort by second element of pair
    for(int i = 0;i < n;i++)
        ct[i] = 0;
    for(int i = 0;i < n;i++)
        ct[a[i].first.second] ++;

    pos[0] = 0;
    for(int i = 1;i < n;i++)
        pos[i] = pos[i - 1] + ct[i - 1];

    for(int i = 0;i < n;i++) {
        aSort[pos[a[i].first.second]] = a[i];
        pos[a[i].first.second] ++;
    }

    swap(a, aSort);

    // Sort by first element of pair
    for(int i = 0;i < n;i++)
        ct[i] = 0;
    for(int i = 0;i < n;i++)
        ct[a[i].first.first] ++;

    pos[0] = 0;
    for(int i = 1;i < n;i++)
        pos[i] = pos[i - 1] + ct[i - 1];

    for(int i = 0;i < n;i++) {
        aSort[pos[a[i].first.first]] = a[i];
        pos[a[i].first.first] ++;
    }

    swap(a, aSort);
}

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

        radixSort();

        p[0] = a[0].second;
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