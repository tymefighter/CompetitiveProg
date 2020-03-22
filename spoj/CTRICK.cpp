#include<iostream>

using namespace std;

const int N = 20005;
int n, ft[N], a[N], b[N];
// a[i] = 1 if ith index is free, a[i] = 0 if ith index is not free

inline int g(int i) {return i & (i + 1);}
inline int h(int i) {return i | (i + 1);}

void init_tree()
{
    for(int i = 0;i < n;i++)
        ft[i] = 0;
}

void update_tree(int i, int x)
{
    while(i < n)
    {
        ft[i] += x;
        i = h(i);
    }
}

int sum_tree(int i)
{
    int val = 0;
    while(i >= 0)
    {
        val += ft[i];
        i = g(i) - 1;
    }
    return val;
}

void init()
{
    for(int i = 0;i < n;i++)
    {
        b[i] = -1;
        a[i] = 1;
        update_tree(i, 1);
    }
}

// Finds j s.t j >= i and a[j] = 1 and j is least possible
int closest_one_to_right(int i)
{
    if(a[i] == 1)
        return i;

    int low = i, high = n - 1, mid, idx_val = n;
    int sum_to_i = sum_tree(i);

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(sum_tree(mid) > sum_to_i)
        {
            idx_val = min(idx_val, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return (idx_val == n ? -1 : idx_val);
}

// Finds the index of the kth one in the array a (0 based)
// So, we find least j s.t sum(a, 0, j) >= k + 1, a[j] would surely be a 1 and sum would be k + 1
int kth_one(int k)
{
    int idx_val = n, value_required = k + 1;
    int low = 0, high = n - 1, mid;
    
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(sum_tree(mid) >= value_required)
        {
            idx_val = min(idx_val, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return (idx_val == n ? -1 : idx_val);
}

void solve()
{
    init();
    int pos = 0, len;

    for(int i = 1;i <= n;i++)
    {
        if((pos = closest_one_to_right(pos)) < 0)
            pos = kth_one(0);

        len = sum_tree(n - 1); // number of ones in a[0..n-1]
        
        int k = (sum_tree(pos) - 1 + i) % len;
        int idx = kth_one(k);

        a[idx] = 0;
        update_tree(idx, -1);
        b[idx] = i;
        pos = idx;
    }

    for(int i = 0;i < n;i++)
        printf("%d ", b[i]);
    printf("\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        solve();
    }
    return 0;
}