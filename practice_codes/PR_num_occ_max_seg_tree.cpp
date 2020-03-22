#include<iostream>
#include<cstring>

using namespace std;

const int N = 100005;
int n, a[N];
pair<int, int> st[4 * N];

inline int left(int i) {return i << 1;}
inline int right(int i) {return (i << 1) + 1;}

void build_tree(int L, int R, int idx)
{
    if(L == R)
    {
        st[idx] = {a[L], 1};
        return;
    }

    int mid = (L + R) >> 1;
    int lc = left(idx), rc = right(idx);

    build_tree(L, mid, lc);
    build_tree(mid + 1, R, rc);

    if(st[lc].first > st[rc].first)
        st[idx] = st[lc];
    else if(st[lc].first < st[rc].first)
        st[idx] = st[rc];
    else
        st[idx] = {st[lc].first, st[lc].second + st[rc].second};
}

pair<int, int> query_tree(int idx, int L, int R, int l, int r)
{
    cout<<L<<" "<<R<<" "<<idx<<" "<<l<<" "<<r<<"--\n";
    if(l > r)
        return {-1, -1};
    if(l == L && r == R)
        return st[idx];
    
    int mid = (L + R) >> 1;
    pair<int, int> lf = query_tree(left(idx), L, mid, l, min(r, mid));
    pair<int, int> rt = query_tree(right(idx), mid + 1, R, max(l, mid + 1), r);

    if(lf.first > rt.first)
        return lf;
    else if(lf.first < rt.first)
        return rt;
    else
        return {rt.first, rt.second + lf.second};
}

void update_tree(int idx, int L, int R, int i, int x)
{
    if(L == R)
    {
        a[i] = x;
        st[idx] = {x, 1};
        return;
    }

    int mid = (L + R) >> 1;
    int lc = left(idx), rc = right(idx);
    if(i <= mid)
        update_tree(lc, L, mid, i, x);
    else
        update_tree(rc, mid + 1, R, i, x);
    
    if(st[lc].first > st[rc].first)
        st[idx] = st[lc];
    else if(st[lc].first < st[rc].first)
        st[idx] = st[rc];
    else
        st[idx] = {st[lc].first, st[lc].second + st[rc].second};
}

void read()
{
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);

    build_tree(0, n - 1, 1);
}

void solve()
{
    static char qry[10];
    while(scanf("%s", qry))
    {
        if(!strcmp(qry, "end"))
            break;
        
        if(strcmp(qry, "qry") == 0)
        {
            int l, r;
            scanf("%d%d", &l, &r);

            pair<int, int> ans_query = query_tree(1, 0, n - 1, l, r);
            printf("max: %d | num of occ: %d\n", ans_query.first, ans_query.second);
        }
        else if(strcmp(qry, "upd") == 0)
        {
            int i, x;
            scanf("%d%d", &i, &x);
            update_tree(1, 0, n - 1, i, x);
        }
    }
}

int main()
{
    read();
    solve();
    return 0;
}