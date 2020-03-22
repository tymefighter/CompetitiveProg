#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

// Mo's algorithm.....
const int MAXVAL = 1e6;

typedef struct DataStruct {
    int m[MAXVAL + 1];
    int num_dist;

    void reset()
    {
        for(int i = 0;i <= MAXVAL;i++)
            m[i] = 0;
        num_dist = 0;
    }

    void remove(int x)
    {
        if(m[x] == 1)
            num_dist --;
        m[x] --;
    }

    void insert(int x)
    {
        if(m[x] == 0)
            num_dist ++;
        m[x] ++;
    }

} DataStruct;

typedef struct Query {
    int index, l, r, ans;
} Query;

const int N = 30000, Q = 200000;
int q, n, a[N], s;
Query qry[Q];
DataStruct ds;

bool comp_MO(const Query &u, const Query &v)
{
    int blk_u = u.l / s;
    int blk_v = v.l / s;
    if(blk_u != blk_v)
        return blk_u < blk_v;
    
    return u.r < v.r;
}

bool compIndex(const Query &u, const Query &v)
{
    return u.index < v.index;
}

void solve()
{
    sort(qry, qry + q, comp_MO);
    int prev_l = -1, prev_r = -1;

    for(int i = 0;i < q;i++)
    {
        int l = qry[i].l, r = qry[i].r;

        if(prev_r < l || r < prev_l)
        {
            if(prev_l != -1)
            {
                for(int j = prev_l;j <= prev_r;j++)
                    ds.remove(a[j]);
            }

            for(int j = l;j <= r;j++)
                ds.insert(a[j]);
        }
        else
        {
            if(prev_l < l)
            {
                for(int j = prev_l;j < l;j++)
                    ds.remove(a[j]);
            }
            else if(prev_l > l)
            {
                for(int j = l;j < prev_l;j++)
                    ds.insert(a[j]);
            }

            if(prev_r < r)
            {
                for(int j = prev_r + 1;j <= r;j++)
                    ds.insert(a[j]);
            }
            else if(prev_r > r)
            {
                for(int j = r + 1;j <= prev_r;j++)
                    ds.remove(a[j]);
            }
        }

        qry[i].ans = ds.num_dist;
        prev_l = l, prev_r = r;
    }
}

int main()
{
    scanf("%d", &n);
    s = ceil(sqrt(n));
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);

    scanf("%d", &q);
    for(int i = 0;i < q;i++)
    {
        scanf("%d %d", &qry[i].l, &qry[i].r);
        qry[i].l --;
        qry[i].r --;
        qry[i].index = i;
    }

    solve();
    sort(qry, qry + q, compIndex);
    for(int i = 0;i < q;i++)
        printf("%d\n", qry[i].ans);
    return 0;
}