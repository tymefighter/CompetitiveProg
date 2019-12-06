#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

int n;
string s;
vector<bitset<26> >st;

int left(int p)
{
    return (p << 1);
}

int right(int p)
{
    return (p << 1) + 1;
}

void build(int p, int L, int R)
{
    if(L == R)
    {
        st[p][s[L] - 'a'] = true;
        return;
    }

    int mid = (L + R) / 2;

    build(left(p), L, mid);
    build(right(p), mid + 1, R);

    st[p] = st[left(p)] | st[right(p)];
}

void update(int p, int L, int R, int idx, char c)
{
    if(L == R)
    {
        st[p].reset();
        st[p][c - 'a'] = true;
        return;
    }

    int mid = (L + R) / 2;

    if(idx <= mid)
        update(left(p), L, mid, idx, c);
    else
        update(right(p), mid + 1, R, idx, c);
    
    st[p] = st[left(p)] | st[right(p)];
}

bitset<26> rbq(int p, int L, int R, int i, int j)
{
    bitset<26> bs;
    bs.reset();

    if(i > R || j < L)
        return bs;
    
    if(i <= L && R <= j)
        return st[p];
    
    int mid = (L + R) / 2;

    return rbq(left(p), L, mid, i, j) | rbq(right(p), mid + 1, R, i, j);
}

void solve()
{
    int q, tp, pos, i, j;
    char c;
    cin>>q;

    while(q--)
    {
        cin>>tp;
        if(tp == 1)
        {
            cin>>pos>>c;
            pos --;
            update(1, 0, n - 1, pos, c);
        }
        else if(tp == 2)
        {
            cin>>i>>j;
            i --, j --;
            cout<<rbq(1, 0, n - 1, i, j).count()<<"\n";
        }
    }
}

int main()
{
    cin>>s;
    n = s.size();

    st.assign(4 * n, bitset<26>(false));
    build(1, 0, n - 1);

    solve();
    return 0;
}