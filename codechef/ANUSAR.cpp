#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>

using namespace std;

const int N = 200005;

char s[N];
int n, p[N], c[N], lcp[N];
int pNew[N], cNew[N], cnt[N], pos[N];
pair<char, int> a[N];

int maxRight[N + 1], l[N], r[N];
long long d[N + 1];

void readInput() {
    scanf("%s ", s);
    n = strlen(s);
    s[n] = '$';
    s[n + 1] = '\0';
    n ++;
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

void computeMaxRange() {
    stack<pair<int, int> > st;
    for(int i = 0;i < n;i++) {
        while(!st.empty() && st.top().first >= lcp[i])
            st.pop();

        l[i] = (st.empty() ? 0 : st.top().second + 1);
        st.push({lcp[i], i});
    }

    while(!st.empty())
        st.pop();

    for(int i = n - 1;i >= 0;i--) {
        while(!st.empty() && st.top().first >= lcp[i])
            st.pop();

        r[i] = (st.empty() ? n - 1 : st.top().second - 1);
        st.push({lcp[i], i});
    }
}

void computeFreq() {
    lcpArray();
    computeMaxRange();

    // for(int i = 0;i < n;i++) {
    //     cout << lcp[i] << " " << l[i] << " " << r[i] << " ";
    //     for(int j = p[i];j < n;j++)
    //         cout << s[j];
    //     cout << "\n";
    // }

    for(int i = 0;i <= n;i++) {
        d[i] = 0;
        maxRight[i] = -1;
    }

    for(int i = 1;i < n;i++) {
        int left = l[i], right = r[i];
        if(maxRight[lcp[i]] >= i)
            continue;

        long long numNewSub = lcp[i]
            - max(
                l[i] == 1 ? 0 : lcp[l[i] - 1],
                r[i] == n - 1 ? 0 : lcp[r[i] + 1]
            );

        d[r[i] - l[i] + 2] += numNewSub * (r[i] - l[i] + 2);
        maxRight[lcp[i]] = r[i];
    }

    for(int i = n;i > 2;i--)
        d[i - 1] += d[i];

    // We do not compute for d[1], hence we must do it 
    // seperately, d[1]: number of distinct substrings
    d[1] = ((long long)n) * (n - 1) / 2;
}

void solveQueries() {
    int q;
    scanf("%d ", &q);
    while(q --) {
        int f;
        scanf("%d ", &f);
        printf("%lld\n", d[f]);
    }
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        readInput();
        computeFreq();
        solveQueries();
    }

    return 0;
}