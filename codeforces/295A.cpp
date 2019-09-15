#include<iostream>
#include<vector>

using namespace std;

typedef struct op
{
    int l, r;
    long long int d;
}op;


int n, m, k;
long long int a[100005], diff[100005], opCount[100005];
op ops[100005];

void read()
{
    cin>>n>>m>>k;

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        diff[i] = 0;
    }

    for(int i = 0;i < m;i++)
    {
        cin>>ops[i].l>>ops[i].r>>ops[i].d;
        ops[i].l --, ops[i].r --;
        opCount[i] = 0;
    }
}

void solve()
{
    int i, x, y;
    for(i = 0;i < k;i++)
    {
        cin>>x>>y;
        x--, y--;
        opCount[x] ++;
        opCount[y + 1] --;
    }

    long long int d = ops[0].d * opCount[0];
    diff[ops[0].l] += d;
    diff[ops[0].r + 1] -= d;

    for(i = 1;i < m;i++)
    {
        opCount[i] += opCount[i - 1];
        d = ops[i].d * opCount[i];
        diff[ops[i].l] += d;
        diff[ops[i].r + 1] -= d;
    }

    a[0] += diff[0];
    cout<<a[0]<<" ";
    for(i = 1;i < n;i++)
    {
        diff[i] += diff[i - 1];
        a[i] += diff[i];
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}