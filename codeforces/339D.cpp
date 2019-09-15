#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, n, m;
vector<int> tree, a;

void read()
{
    cin>>N>>m;
    n = (int)pow(2, N);

    a.resize(n);
    tree.assign(4 * n, -1);

    for(int i = 0;i < n;i++)
        cin>>a[i];
}

int left(int p)
{
    return p << 1;
}

int right(int p)
{
    return (p << 1) + 1;
}

void build(int p, int L, int R)
{
    static int op;

    if(L == R)
    {
        op = 0;
        tree[p] = a[L];
        return;
    }

    int mid = (L + R) / 2;
    build(left(p), L, mid);
    build(right(p), mid + 1, R);

    op ++;

    if(op % 2)
        tree[p] = tree[left(p)] | tree[right(p)];
    else
        tree[p] = tree[left(p)] ^ tree[right(p)];
}

void update(int p, int L, int R, const int &idx, const int &val)
{
    static int op;

    if(L == R)
    {
        op = 0;
        tree[p] = val;
        return;
    }

    int mid = (L + R) / 2;

    if(idx <= mid)
        update(left(p), L, mid, idx, val);
    else
        update(right(p), mid + 1, R, idx, val);

    op ++;

    if(op % 2)
        tree[p] = tree[left(p)] | tree[right(p)];
    else
        tree[p] = tree[left(p)] ^ tree[right(p)];
}

void solve()
{
    int idx, val;
    for(int i = 0;i < m;i++)
    {
        cin>>idx>>val;
        idx --;
        update(1, 0, n - 1, idx, val);
        cout<<tree[1]<<"\n";
    }
}

int main()
{
    read();
    build(1, 0, n - 1);
    solve();

    return 0;
}