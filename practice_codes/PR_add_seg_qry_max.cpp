#include<iostream>

using namespace std;

const int N = 100005, INF = 100005;
int n, a[N];
int t[4 * N], lazy[4 * N];
// st[idx] = max of a[L..R], lazy[idx] = value to be added to a[L..R]
// where L..R are is the range corresponding to index idx

inline int left(int i) {return i << 1;}
inline int right(int i){return (i << 1) + 1;}

// Build tree using array a[0..n-1]
void build_tree(int idx, int L, int R)
{
    if(L == R)
    {
        t[idx] = a[L];
        lazy[idx] = 0;
        return;
    }

    int mid = (L + R) >> 1;
    build_tree(left(idx), L, mid);
    build_tree(right(idx), mid + 1, R);

    t[idx] = max(t[left(idx)], t[right(idx)]);
    lazy[idx] = 0;
}

void push(int idx)
{
    int lc = left(idx), rc = right(idx);

    t[lc] += lazy[idx];
    lazy[lc] += lazy[idx];
    t[rc] += lazy[idx];
    lazy[rc] += lazy[idx];
    lazy[idx] = 0;
}

// Increment a[l..r] by x
void range_update(int idx, int L, int R, int l, int r, int x)
{
    if(l > r)
        return;
    

    if(l == L && r == R)
    {
        t[idx] += x;
        lazy[idx] = x;
        return;
    }

    int mid = (L + R) >> 1;
    push(idx); // push lazy computation below

    range_update(left(idx), L, mid, l, min(mid, r), x);
    range_update(right(idx), mid + 1, R, max(l, mid + 1), r, x);

    t[idx] = max(t[left(idx)], t[right(idx)]);
}

int query(int idx, int L, int R, int l, int r)
{
    if(l > r)
        return -INF;

    if(l == L && r == R)
        return t[idx];
    
    int mid = (L + R) >> 1;
    push(idx);
    return max(query(left(idx), L, mid, l, min(r, mid)), 
        query(right(idx), mid + 1, R, max(mid + 1, l), r));
}

void solve()
{
    static char qry[10];
    while(scanf("%s", qry))
    {
        if(strcmp(qry, "end") == 0)
            break;
        else if(strcmp(qry, "max") == 0)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query(1, 0, n - 1, l, r));
        }
        else if(strcmp(qry, "update") == 0)
        {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            range_update(1, 0, n - 1, l, r, x);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    build_tree(1, 0, n - 1);
    solve();
    return 0;
}