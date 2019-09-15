#include<iostream>
#include<vector>

using namespace std;

int n, k;
int a[100005];
vector<long long int> st;

void read()
{
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        if(a[i] < 0)
            a[i] = -1;
        else if(a[i] > 0)
            a[i] = 1;
        else
            a[i] = 0;
    }
    
    st.clear();
    st.assign(4 * n, -1);
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
    if(L == R)
    {
        st[p] = a[L];
        return;
    }

    int mid = (L + R) / 2;
    build(left(p), L, mid);
    build(right(p), mid + 1, R);

    st[p] = st[left(p)] * st[right(p)];
}

int rpq(int p, int L, int R, const int &i, const int &j)
{
    if(i > R || j < L)
        return 1;
    
    if(i <= L && R <= j)
        return st[p];

    int mid = (L + R) / 2;
    return rpq(left(p), L, mid, i, j) * rpq(right(p), mid + 1, R, i, j);
}

void update(int p, int L, int R, const int &idx, const int &val)
{
    if(L == R)
    {
        st[p] = val;
        return;
    }

    int mid = (L + R) / 2;

    if(idx <= mid)
        update(left(p), L, mid, idx, val);
    else
        update(right(p), mid + 1, R, idx, val);
    
    st[p] = st[left(p)] * st[right(p)];
}

void solve()
{
    char cmd;
    int idx, val, i, j;
    string s;
    while(k--)
    {
        cin>>cmd;

        if(cmd == 'P')
        {
            cin>>i>>j;
            i --, j --;
            val = rpq(1, 0, n - 1, i, j);
            if(val < 0)
                s.push_back('-');
            else if(val > 0)
                s.push_back('+');
            else
                s.push_back('0');
        }
        else if(cmd == 'C')
        {
            cin>>idx>>val;
            if(val < 0)
                val = -1;
            else if(val > 0)
                val = 1;
            else
                val = 0;
            idx --;
            update(1, 0, n - 1, idx, val);
        }
    }


    cout<<s<<"\n";
}

int main()
{
    while(cin>>n>>k)
    {
        read();
        build(1, 0, n - 1);
        solve();
    }
    return 0;
}