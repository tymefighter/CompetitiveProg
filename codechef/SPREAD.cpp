#include<iostream>

using namespace std;

const int N = 1e6 + 3;
long long ft[N];
int n, m, c;

inline int g(int i)
{
    return i & (i + 1);
}

inline int h(int i)
{
    return i | (i + 1);
}

// These won't be directly used
void init()
{
    for(int i = 0;i < n;i++)
        ft[i] = 0ll;
}

long long rmq(int r)
{
    long long val = 0;
    while(r >= 0)
    {
        val += ft[r];
        r = g(r) - 1;
    }
    return val;
}

void inc(int idx, int val)
{
    while(idx <= n - 1)
    {
        ft[idx] += (long long)val;
        idx = h(idx);
    }
}

// These would be the actual interface
long long point_query(int idx)
{
    return rmq(idx);
}

void range_inc(int l, int r, int val)
{
    inc(l, val);
    if(r < n - 1)
        inc(r + 1, -val);
}

// Handling the queries
char query[3];
void solve()
{
    range_inc(0, n - 1, c);
    while(m --)
    {
        scanf("%s", query);
        if(query[0] == 'S')
        {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            l --, r --;
            range_inc(l, r, x);
        }
        else if(query[0] == 'Q')
        {
            int idx;
            scanf("%d", &idx);
            idx --;
            printf("%lld\n", point_query(idx));
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &c);
    init();
    solve();
    return 0;
}