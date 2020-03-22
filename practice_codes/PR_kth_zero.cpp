#include<iostream>

using namespace std;

const int N = 100005;
int n, a[N];
int st[4 * N];

inline int left(int i) {return i << 1;}
inline int right(int i) {return (i << 1) + 1;}

void build_tree(int idx, int L, int R)
{
    if(L == R)
    {
        st[idx] = (a[L] == 0 ? 1 : 0);
        return;
    }

    int mid = (L + R) >> 1;
    int lc = left(idx), rc = right(idx);

    build_tree(lc, L, mid);
    build_tree(rc, mid + 1, R);
    st[idx] = st[lc] + st[rc];
}

int k_th_zero(int idx, int L, int R, int k)
{
    if(k == 0 || st[idx] < k)
        return -1;

    if(L == R)
        return L;

    int mid = (L + R) >> 1;
    if(st[left(idx)] >= k)
        return k_th_zero(left(idx), L, mid, k);
    else
        return k_th_zero(right(idx), mid + 1, R, k - st[left(idx)]);
}

void update_tree(int idx, int L, int R, int i, int x)
{
    if(L == R)
    {
        a[L] = x;
        st[idx] = (x == 0 ? 1 : 0);
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
        else if(strcmp(query, "zero") == 0)
        {
            int k;
            scanf("%d", &k);
            printf("Index of kth zero: %d\n", k_th_zero(1, 0, n - 1, k));
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