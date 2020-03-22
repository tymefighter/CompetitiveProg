#include<iostream>

using namespace std;

const int N = 100005;
int n, a[N], st[4 * N];

/*
    Assumption: All values are in array a are non-negative
    st[idx] = sum of a[i] for L to R (where idx corresponds to [L, R])
*/

inline int left(int i) {return i << 1;}
inline int right(int i) {return (i << 1) + 1;}

void build_tree(int idx, int L, int R)
{
    if(L == R)
    {
        st[idx] = a[L];
        return;
    }

    int mid = (L + R) >> 1;
    int lc = left(idx), rc = right(idx);

    build_tree(lc, L, mid);
    build_tree(rc, mid + 1, R);

    st[idx] = st[lc] + st[rc];
}

int prefix_with_sum(int idx, int L, int R, int sum_val)
{
    if(st[idx] < sum_val)
        return -1;
    
    if(L == R)
    {
        if(st[idx] != sum_val)
            return -1;
        else
            return L;
    }

    int mid = (L + R) >> 1;
    if(st[left(idx)] >= sum_val)
        return prefix_with_sum(left(idx), L, mid, sum_val);
    else
        return prefix_with_sum(right(idx), mid + 1, R, sum_val - st[left(idx)]);
}

void update_tree(int idx, int L, int R, int i, int x)
{
    if(L == R)
    {
        a[L] = st[idx] = x;
        return;
    }

    int mid = (L + R) >> 1;
    if(i <= mid)
        update_tree(left(idx), L, mid, i, x);
    else
        update_tree(right(idx), mid + 1, R, i, x);
    
    st[idx] = st[left(idx)] + st[right(idx)];
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
    static char query[10];
    while(scanf("%s", query))
    {
        if(strcmp(query, "end") == 0)
            break;
        else if(strcmp(query, "val") == 0)
        {
            int sum_val;
            scanf("%d", &sum_val);
            printf("Index till where to sum: %d\n", prefix_with_sum(1, 0, n - 1, sum_val));
        }
        else if(strcmp(query, "update") == 0)
        {
            int i, x;
            scanf("%d %d", &i, &x);
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