#include<iostream>
#include<cstring>

using namespace std;

const int N = 1024;
int n;
long long t[N][N], a[N][N];

inline int g(int i) {return i & (i + 1);}
inline int h(int i) {return i | (i + 1);}

void init_tree()
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
            a[i][j] = t[i][j] = 0;
    }
}

long long sum_tree(int r, int c)
{
    int p = r, q;
    long long val = 0;
    
    while(p >= 0)
    {
        q = c;
        while(q >= 0)
        {
            val += t[p][q];
            q = g(q) - 1;
        }
        p = g(p) - 1;
    }

    return val;
}

void update_tree(int r, int c, int x)
{
    int p = r, q;

    while(p < n)
    {
        q = c;
        while(q < n)
        {
            t[p][q] += x;
            q = h(q);
        }
        p = h(p);
    }
}

long long subarray_sum(int r1, int c1, int r2, int c2)
{
    return sum_tree(r2, c2)
        - (r1 > 0 ? sum_tree(r1 - 1, c2) : 0)
        - (c1 > 0 ? sum_tree(r2, c1 - 1) : 0)
        + (r1 > 0 && c1 > 0 ? sum_tree(r1 - 1, c1 - 1) : 0);
}

void read()
{
    init_tree();
    scanf("%d", &n);
}

void solve_queries()
{
    static char qry[10];
    
    while(scanf("%s", qry))
    {
        if(strcmp(qry, "END") == 0)
            break;
        else if(strcmp(qry, "SUM") == 0)
        {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf("%lld\n", subarray_sum(y1, x1, y2, x2));
        }
        else if(strcmp(qry, "SET") == 0)
        {
            int x, y, val;
            scanf("%d %d %d", &x, &y, &val);
            update_tree(y, x, val - a[y][x]);
            a[y][x] = val;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        read();
        solve_queries();
    }

    return 0;
}