#include<iostream>
#include<cmath>
#include<cassert>
#include<algorithm>

using namespace std;

const int N = 5e5 + 5;
const int SQRTN = 800;
int n, s, num_b, a[N], b[SQRTN][SQRTN];

// The algorithm used is very slow.....
void build_block()
{
    s = ceil(sqrt(n));
    num_b = (n / s) + (n % s == 0 ? 0 : 1);

    for(int i = 0;i < num_b - 1;i++)
    {
        for(int j = 0;j < s;j++)
            b[i][j] = a[i * s + j];

        sort(b[i], b[i] + s);
    }

    int size_last_blk = min(s, n - s * (num_b - 1));

    for(int j = 0;j < size_last_blk;j++)
        b[num_b - 1][j] = a[s * (num_b - 1) + j];

    sort(b[num_b - 1], b[num_b - 1] + size_last_blk);
}

int b_search(int blk, int val)
{
    int low = 0, high = (blk == num_b - 1 ? min(s, n - s * (num_b - 1)) : s) - 1; 
    int idx_val = high + 1, mid;
    if(b[blk][high] < val)
        return high + 1;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(b[blk][mid] >= val)
        {
            idx_val = min(idx_val, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return idx_val;
}

int num_ele(const int &l, const int &r, const int &x)
{
    int cl = l / s, cr = r / s, count_val = 0;

    if(cl == cr)
    {
        for(int i = l;i <= r;i++)
            count_val += (a[i] >= x ? 1 : 0);
        return count_val;
    }

    for(int i = l;i <= (cl + 1) * s - 1;i++)
        count_val += (a[i] >= x ? 1 : 0);
    
    for(int j = cl + 1;j <= cr - 1;j++)
    {
        // surely this won't be the last block, so size = s always
        assert(j != num_b - 1);
        int val = b_search(j, x);
        count_val += s - val;
    }
    
    for(int i = cr * s;i <= r;i++)
        count_val += (a[i] >= x ? 1 : 0);
    
    return count_val;
}

void update_ele(const int &i, const int &x)
{
    int blk = i / s;
    int idx = b_search(blk, a[i]);
    assert(idx != s);

    a[i] = x;
    b[blk][idx] = x;
    int block_size = (blk == num_b - 1 ? min(s, n - s * (num_b - 1)) : s);
    sort(b[blk], b[blk] + block_size);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    build_block();

    int q;
    scanf("%d", &q);
    while(q--)
    {
        int qry;
        scanf("%d", &qry);
        if(!qry)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            l --, r --;
            printf("%d\n", num_ele(l, r, x));
        }
        else
        {
            int i, x;
            scanf("%d%d", &i, &x);
            i --;
            update_ele(i, x);
        }
    }
    return 0;
}