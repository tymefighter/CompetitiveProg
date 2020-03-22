#include<iostream>

using namespace std;

typedef struct Data {
    int sum, max_prefix_sum, max_suffix_sum, max_seg_sum;
} Data;

const int N = 50005;
int n, a[N];
Data st[4 * N];

inline int left(int i) {return i << 1;}
inline int right(int i){return (i << 1) + 1;}

int max(const int &u, const int &v, const int &w){return max(max(u, v), w);}

Data make_node(int i)
{
    Data d;
    d.sum = d.max_prefix_sum = d.max_suffix_sum = d.max_seg_sum = a[i];
    return d;
}

Data combine(Data l, Data r)
{
    Data comb;
    comb.sum = l.sum + r.sum;
    comb.max_prefix_sum = max(l.max_prefix_sum, l.sum + r.max_prefix_sum);
    comb.max_suffix_sum = max(l.max_suffix_sum + r.sum, r.max_suffix_sum);
    comb.max_seg_sum = max(l.max_seg_sum, l.max_suffix_sum + r.max_prefix_sum, r.max_seg_sum);
    return comb;
}

void build_tree(int idx, int L, int R)
{
    if(L == R)
    {
        st[idx] = make_node(L);
        return;
    }

    int mid = (L + R) >> 1;
    build_tree(left(idx), L, mid);
    build_tree(right(idx), mid + 1, R);
    st[idx] = combine(st[left(idx)], st[right(idx)]);
}

Data query(int idx, int L, int R, int l, int r)
{
    if(l == L && R == r)
        return st[idx];
    
    int mid = (L + R) >> 1;
    if(l <= mid && r > mid)
        return combine(query(left(idx), L, mid, l, mid), query(right(idx), mid + 1, R, mid + 1,r ));
    else if(l > mid)
        return query(right(idx), mid + 1, R, l, r);
    else
        return query(left(idx), L, mid, l, r);
}

void update(int idx, int L, int R, int i, int x)
{
    if(L == R)
    {
        a[L] = x;
        st[idx] = make_node(L);
        return;
    }

    int mid = (L + R) >> 1;
    if(i <= mid)
        update(left(idx), L, mid, i, x);
    else
        update(right(idx), mid + 1, R, i, x);
    
    st[idx] = combine(st[left(idx)], st[right(idx)]);
}

void read()
{
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    
    build_tree(1, 0, n - 1);
}

void solve()
{
    int m;
    scanf("%d", &m);
    while(m --)
    {
        int qry;
        scanf("%d", &qry);
        if(!qry)
        {
            int i, x;
            scanf("%d %d", &i, &x);
            i --;
            update(1, 0, n - 1, i, x);
        }
        else
        {
            int l, r;
            scanf("%d %d", &l, &r);
            l --, r --;
            printf("%d\n", query(1, 0, n - 1, l, r).max_seg_sum);
        }
    }
}

int main()
{
    read();
    solve();
    return 0;
}