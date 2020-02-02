#include<iostream>
#include<vector>

using namespace std;

int q, x, count_x[400005];
int st[1600020]; // index

int left(int p)
{
    return (p << 1);
}

int right(int p)
{
    return (p << 1) + 1;
}
void build_st(int p, int L, int R)
{
    st[p] = L;
    if(L == R)
        return;
    
    int mid = (L + R) / 2;
    build_st(left(p), L, mid);
    build_st(right(p), mid + 1, R);
}

void reset()
{
    for(int i = 0;i < x;i++)
        count_x[i] = 0;

    build_st(1, 0, x - 1);
}


void update(int p, int L, int R, int idx)
{
    if(L == R)
    {
        count_x[L] ++;
        return;
    }

    int mid = (L + R) / 2;

    if(idx <= mid)
        update(left(p), L, mid, idx);
    else
        update(right(p), mid + 1, R, idx);

    if(count_x[st[left(p)]] <= count_x[st[right(p)]]) // pick the leftmost index
        st[p] = st[left(p)];
    else
        st[p] = st[right(p)];
}

int rmq(int p, int L, int R, int i, int j)
{
    if(L > j || i > R)
        return -1;
    
    if(i <= L && R <= j)
        return st[p];

    int mid = (L + R) / 2;
    int idx1 = rmq(left(p), L, mid, i, j);
    int idx2 = rmq(right(p), mid + 1, R, i, j);

    if(idx1 == -1)
        return idx2;
    else if(idx2 == -1)
        return idx1;
    else
    {
        if(count_x[idx1] <= count_x[idx2])
            return idx1;
        else
            return idx2;
    }
}

void solve()
{
    int val;
    while(q--)
    {
        cin>>val;
        update(1, 0, x - 1, val % x);

        int minIdx = rmq(1, 0, x - 1, 0, x - 1);
        int minVal = count_x[minIdx];
        cout<<minVal * x + minIdx<<"\n";
    }
}

int main()
{
    cin>>q>>x;
    reset();
    solve();
    return 0;
}