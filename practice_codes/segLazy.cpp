#include<iostream>
#include<vector>

using namespace std;

class SegmentTree
{
    private:
    vector<int> st, lazy;
    int n;
    
    int left(int p)
    {
        return p << 1;
    }

    int right(int p)
    {
        return (p << 1) + 1;
    }

    void build(const vector<int> &a, int p, int L, int R)
    {
        if(L == R)
        {
            st[p] = a[L];
            return;
        }

        build(a, left(p), L, (L + R) / 2);
        build(a, right(p), (L + R) / 2 + 1, R);

        st[p] = st[left(p)] + st[right(p)];        
    }

    int rsq(int p, int L, int R, const int &i, const int &j)
    {
        if(lazy[p] != 0)
        {
            st[p] += (R - L + 1) * lazy[p];

            if(L != R)
            {
                lazy[left(p)] += lazy[p];
                lazy[right(p)] += lazy[p];
            }

            lazy[p] = 0;
        }

        if(i > R || j < L)
            return 0;

        if(i <= L && R <= j)
            return st[p];
        
        int mid = (L + R) / 2;

        return rsq(left(p), L, mid, i, j) + rsq(right(p), mid + 1, R, i, j);
    }

    void update(int p, int L, int R, const int &idx, const int &val)
    {
        if(lazy[p] != 0)
        {
            st[p] += (R - L + 1) * lazy[p];

            if(L != R)
            {
                lazy[left(p)] += lazy[p];
                lazy[right(p)] += lazy[p];
            }

            lazy[p] = 0;
        }

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

        st[p] = st[left(p)] + st[right(p)];
    }

    void lazyUpdate(int p, int L, int R, const int &i, const int &j)
    {
        if(lazy[p] != 0)                    // previous updates
        {
            st[p] += (R - L + 1) * lazy[p];

            if(L != R)
            {
                lazy[left(p)] += lazy[p];
                lazy[right(p)] += lazy[p];
            }

            lazy[p] = 0;
        }

        if(i > R || j < L)
            return;
        
        if(i <= L && R <= j)
        {
            st[p] += R - L + 1;

            if(L != R)
            {
                lazy[left(p)] += 1;
                lazy[right(p)] += 1;
            }

            return;
        }

        int mid = (L + R) / 2;
        lazyUpdate(left(p), L, mid, i, j);
        lazyUpdate(right(p), mid + 1, R, i, j);
        
        st[p] = st[left(p)] + st[right(p)];
    }

    public:

    void reset(const vector<int> &arr)
    {
        n = arr.size();
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        build(arr, 1, 0, n - 1);
    }

    int rsq(int i, int j)
    {
        return rsq(1, 0, n - 1, i, j);
    }

    void update(int idx, int val)
    {
        update(1, 0, n - 1, idx, val);
    }

    void lazyUpdate(int i, int j)
    {
        lazyUpdate(1, 0, n - 1, i, j);
    }
};