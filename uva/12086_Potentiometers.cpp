#include<iostream>
#include<cstring>

using namespace std;

const int N = 200005;
int n, a[N], ft[N];

inline int g(int i)
{
    return i & (i + 1);
}

inline int h(int i)
{
    return i | (i + 1);
}

void initFT()
{
    for(int i = 0;i < n;i++)
        ft[i] = 0;
}

void update(int idx, int val)
{
    while(idx < n)
    {
        ft[idx] += val;
        idx = h(idx);
    }
}

int rmq(int r)
{
    int val = 0;
    while(r >= 0)
    {
        val += ft[r];
        r = g(r) - 1;
    }
    return val;
}

int rmq(int l, int r)
{
    return rmq(r) - (l > 0 ? rmq(l - 1) : 0);
}

void read()
{
    initFT();

    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
        update(i, a[i]);
    }
}

char query[10];

void solve()
{
    while(scanf("%s", query))
    {
        if(strcmp(query, "END") == 0)
            break;
        if(query[0] == 'M')
        {
            int l, r;
            scanf("%d %d", &l, &r);
            l --, r --;
            printf("%d\n", rmq(l, r));
        }
        else if(query[0] == 'S')
        {
            int idx, val;
            scanf("%d %d", &idx, &val);
            idx --;
            update(idx, val - a[idx]);
            a[idx] = val;
        }
    }
}

int main()
{
    int case_no = 1;
    while(scanf("%d", &n))
    {
        if(!n)
            break;
        if(case_no > 1)
            printf("\n");
        printf("Case %d:\n", case_no);
        read();
        solve();
        case_no ++;
    }
    return 0;
}