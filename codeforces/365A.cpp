#include<iostream>

using namespace std;

const int N = 3e5;
int n, m;
bool st[4 * N];
int ans[N];

inline int left(int i) {return i << 1;}
inline int right(int i){return (i << 1) + 1;}

void build_tree(int idx, int L, int R)
{
    if(L == R)
    {
        ans[L] = -1;
        st[idx] = true;
        return;
    }

    int mid = (L + R) >> 1;
    build_tree(left(idx), L, mid);
    build_tree(right(idx), mid + 1, R);
    st[idx] = st[left(idx)] | st[right(idx)];
}

// time = num alive in l to r
void eliminate_range(int idx, int L, int R, int l, int r, int x)
{
    if(L == R)
    {
        if(L != x)
        {
            st[idx] = false;
            ans[L] = x;
        }
        return;
    }

    int mid = (L + R) >> 1;
    if(l <= mid && st[left(idx)])
        eliminate_range(left(idx), L, mid, l, min(mid + 1, r), x);
    if(r > mid && st[right(idx)])
        eliminate_range(right(idx), mid + 1, R, max(l, mid + 1), r, x);
    
    st[idx] = st[left(idx)] | st[right(idx)];
}

int main()
{
    scanf("%d%d", &n, &m);
    build_tree(1, 0, n - 1);

    for(int i = 0;i < m;i++)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        l --, r --, x --;
        eliminate_range(1, 0, n - 1, l, r, x);  // Eliminate all in l to r except x
                                                // time taken = num_alive(l, r) * log(n)
    }

    for(int i = 0;i < n;i++)
        printf("%d ", ans[i] + 1);
    printf("\n");
    return 0;
}