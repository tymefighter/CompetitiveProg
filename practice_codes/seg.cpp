#include<iostream>
#include<vector>

using namespace std;


class SegmentTree
{
    private:
    int n;
    vector<int> st, a;

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
            st[p] = L;
            return;
        }

        build(left(p), L, (L + R) / 2);
        build(right(p), (L + R) / 2 + 1, R);

        int p1 = st[left(p)], p2 = st[right(p)];
        if(a[p1] <= a[p2])
            st[p] = p1;
        else
            st[p] = p2; 
    }

    int rmq(int p, int L, int R, const int &i, const int &j)
    {
        if(i > R || j < L)
            return -1;
        
        if(i <= L && R <= j)
            return st[p];
        
        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

        if(p1 == -1)
            return p2;
        else if(p2 == -1)
            return p1;
        else
        {
            if(a[p1] <= a[p2])
                return p1;
            else
                return p2;
        }
    }

    void update(int p, int L, int R, const int &idx)
    {
        if(L == R)
            return;
        
        int mid = (L + R) / 2;

        if(idx <= mid)
            update(left(p), L, mid, idx);
        else
            update(right(p), mid + 1, R, idx);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        if(a[p1] <= a[p2])
            st[p] = p1;
        else
            st[p] = p2;
    }

    public:

    void reset(vector<int> arr)
    {
        a = arr;
        n = a.size();
        st.assign(4 * n, -1);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j)
    {
        return rmq(1, 0, n - 1, i, j);
    }

    void update(int idx, int val)
    {
        a[idx] = val;
        update(1, 0, n - 1, idx);
    }
};

vector<int> a;
int n;
SegmentTree st;

void read()
{
    cin>>n;
    a.resize(n);
    for(int i = 0;i < n;i++)
        cin>>a[i];

    st.reset(a);
}

void solve()
{
    string s;
    int i, j;
    int idx, val;

    while(true)
    {
        cin>>s;

        if(s == "rmq")
        {
            cin>>i>>j;
            cout<<st.rmq(i, j)<<"\n";
        }
        else if(s == "up")
        {
            cin>>idx>>val;
            st.update(idx, val);
        }
        else
            break;
    }
}

int main()
{
    read();
    solve();
    return 0;
}