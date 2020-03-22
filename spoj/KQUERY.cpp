#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

const int N = 30000;
int n, a[N];
vector<int> st[4 * N];
// Merge sort Tree

inline int left(int i){return i << 1;}
inline int right(int i){return (i << 1) + 1;}

void merge(vector<int> &mrg, const vector<int> &u, const vector<int> &v)
{
    int m = 0, p = 0, q = 0;
    while(p < u.size() || q < v.size())
    {
        if(p == u.size())
        {
            mrg[m] = v[q];
            q ++;
        }
        else if(q == v.size())
        {
            mrg[m] = u[p];
            p ++;
        }
        else
        {
            if(u[p] < v[q])
            {
                mrg[m] = u[p];
                p ++;
            }
            else
            {
                mrg[m] = v[q];
                q ++;
            }
        }
        m ++;
    }
}

void build_tree(int idx, int L, int R)
{
    if(L == R)
    {
        st[idx].clear();
        st[idx].resize(1);
        st[idx][0] = a[L];
        return;
    }

    int mid = (L + R) >> 1;
    build_tree(left(idx), L, mid);
    build_tree(right(idx), mid + 1, R);

    st[idx].clear();
    st[idx].resize(st[left(idx)].size() + st[right(idx)].size());
    merge(st[idx], st[left(idx)], st[right(idx)]);
}

// gives number of elements greater than x
int b_search(const vector<int> &v, int x)
{
    int low = 0, high = v.size() - 1, mid, ans = v.size();
    if(v[high] <= x)
        return 0;

    while(low <= high)
    {
        mid = (low + high) >> 1;
        if(v[mid] > x)
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return v.size() - ans;
}

int query(int idx, int L, int R, int l, int r, int x)
{
    if(l > r)
        return 0;

    if(l == L && r == R)
        return b_search(st[idx], x);
    
    int mid = (L + R) >> 1;
    return query(left(idx), L, mid, l, min(mid, r), x)
        + query(right(idx), mid + 1, R, max(l, mid + 1), r, x);
}

void solve()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        l --, r --;
        printf("%d\n", query(1, 0, n - 1, l, r, x));
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