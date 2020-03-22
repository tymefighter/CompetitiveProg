#include<iostream>
#include<algorithm>

using namespace std;

typedef struct Query {
    int index, l, r, ans;
} Query;

const int N = 30000, Q = 200000, MAXVAL = 1000000;
Query qry[Q];
int n, q, a[N];

int t[N], last_idx[MAXVAL + 1];

inline int g(int i) {return i & (i + 1);}
inline int h(int i) {return i | (i + 1);}

void init_tree()
{
    for(int i = 0;i < n;i++)
        t[i] = 0;
}

void update_tree(int i, int x)
{
    while(i < n)
    {
        t[i] += x;
        i = h(i);
    }
}

int sum_tree(int i)
{
    int sum_val = 0;
    while(i >= 0)
    {
        sum_val += t[i];
        i = g(i) - 1;
    }
    return sum_val;
}

int range_sum_tree(int l, int r)
{
    return sum_tree(r) - (l > 0 ? sum_tree(l - 1) : 0);
}

bool comp_r_values(const Query &x, const Query &y){return x.r < y.r;}
bool compare_indices(const Query &x, const Query &y) {return x.index < y.index;}

void read()
{
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);

    scanf("%d", &q);
    for(int i = 0;i < q;i++)
    {
        qry[i].index = i;
        scanf("%d %d", &qry[i].l, &qry[i].r);
        qry[i].l --;
        qry[i].r --;
    }
}

void solve_offline_queries()
{
    sort(qry, qry + q, comp_r_values);
    init_tree();

    for(int i = 0;i < n;i++)
        last_idx[a[i]] = -1;

    int query_number = 0;
    for(int i = 0;i < n;i++)
    {
        if(last_idx[a[i]] != -1)
            update_tree(last_idx[a[i]], -1);

        last_idx[a[i]] = i;
        update_tree(i, 1);

        while(query_number < q && qry[query_number].r == i)
        {
            qry[query_number].ans = range_sum_tree(qry[query_number].l, qry[query_number].r);
            query_number ++;
        }
    }

    sort(qry, qry + q, compare_indices);
}

int main()
{
    read();
    solve_offline_queries();
    for(int i = 0;i < q;i++)
        printf("%d\n", qry[i].ans);
    return 0;
}