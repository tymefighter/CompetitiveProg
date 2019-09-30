#include<iostream>
#include<vector>

using namespace std;

class SegmentTree
{
    private:
    int n;
    vector<int> st, tree; 
    // In 'tree' -> 0: nothing, 1: conv to 1, 2: conv to 0, 3: invert
    // st[p] stores the sum of elements of some segment L..R

    int left(int p)
    {
        return (p << 1);
    }

    int right(int p)
    {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R, const vector<int> &a)
    {
        if(L == R)
        {
            st[p] = a[L];
            return;
        }

        int mid = (L + R) / 2;
        build(left(p), L, mid, a);
        build(right(p), mid + 1, R, a);

        st[p] = st[left(p)] + st[right(p)];
    }

    void update(int p, int L, int R, const int &i, const int &j, const int &q)
    {
        if(tree[p] == 1)
        {
            if(L != R)
            {
                tree[left(p)] = 1;
                tree[right(p)] = 1;
            }
            st[p] = (R - L + 1);
        }
        else if(tree[p] == 2)
        {
            if(L != R)
            {
                tree[left(p)] = 2;
                tree[right(p)] = 2;
            }
            st[p] = 0;
        }
        else if(tree[p] == 3)
        {
            if(L != R)
            {
                int l = left(p), r = right(p);
                if(tree[l] == 1)
                    tree[l] = 2;
                else if(tree[l] == 2)
                    tree[l] = 1;
                else if(tree[l] == 3)
                    tree[l] = 0;
                else
                    tree[l] = 3;
        
                if(tree[r] == 1)
                    tree[r] = 2;
                else if(tree[r] == 2)
                    tree[r] = 1;
                else if(tree[r] == 3)
                    tree[r] = 0;
                else
                    tree[r] = 3;
            }
            
            st[p] = (R - L + 1) - st[p];
        }

        tree[p] = 0;

        if(i > R || j < L)
            return;
        
        if(i <= L && R <= j)
        {
            if(q == 1)
            {
                st[p] = (R - L + 1);
                if(L != R)
                {
                    tree[left(p)] = 1;
                    tree[right(p)] = 1;
                }
            }
            else if(q == 2)
            {
                st[p] = 0;
                if(L != R)
                {
                    tree[left(p)] = 2;
                    tree[right(p)] = 2;
                }
            }
            else if(q == 3)
            {
                st[p] = (R - L + 1) - st[p];
                
                if(L != R)
                {
                    int l = left(p), r = right(p);
                    if(tree[l] == 1)
                        tree[l] = 2;
                    else if(tree[l] == 2)
                        tree[l] = 1;
                    else if(tree[l] == 3)
                        tree[l] = 0;
                    else
                        tree[l] = 3;
            
                    if(tree[r] == 1)
                        tree[r] = 2;
                    else if(tree[r] == 2)
                        tree[r] = 1;
                    else if(tree[r] == 3)
                        tree[r] = 0;
                    else
                        tree[r] = 3;
                }
            }
            return;
        }

        int mid = (L + R) / 2;
        update(left(p), L, mid, i, j, q);
        update(right(p), mid + 1, R, i, j, q);

        st[p] = st[left(p)] + st[right(p)];
    }

    int rsq(int p, int L, int R, const int &i, const int &j)
    {
        if(tree[p] == 1)
        {
            if(L != R)
            {
                tree[left(p)] = 1;
                tree[right(p)] = 1;
            }
            st[p] = (R - L + 1);
        }
        else if(tree[p] == 2)
        {
            if(L != R)
            {
                tree[left(p)] = 2;
                tree[right(p)] = 2;
            }
            st[p] = 0;
        }
        else if(tree[p] == 3)
        {
            if(L != R)
            {
                int l = left(p), r = right(p);
                if(tree[l] == 1)
                    tree[l] = 2;
                else if(tree[l] == 2)
                    tree[l] = 1;
                else if(tree[l] == 3)
                    tree[l] = 0;
                else
                    tree[l] = 3;
        
                if(tree[r] == 1)
                    tree[r] = 2;
                else if(tree[r] == 2)
                    tree[r] = 1;
                else if(tree[r] == 3)
                    tree[r] = 0;
                else
                    tree[r] = 3;
            }
            st[p] = (R - L + 1) - st[p];
        }

        tree[p] = 0;

        if(i > R || j < L)
            return 0;
        
        if(i <= L && R <= j)
            return st[p];
        
        int mid = (L + R) / 2;
        return rsq(left(p), L, mid, i, j) + rsq(right(p), mid + 1, R, i, j);
    }

    public:

    void reset(const vector<int> &a)
    {
        st.clear();
        tree.clear();

        n = a.size();
        st.assign(4 * n, 0);
        tree.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void update(const int &i, const int &j, const int &q)
    {
        update(1, 0, n - 1, i, j, q);
    }

    int rsq(const int &i, const int &j)
    {
        return rsq(1, 0, n - 1, i, j);
    }
};

SegmentTree st;

void read()
{
    string s, x;
    int m, t;

    cin>>m;
    while(m --)
    {
        cin>>t;
        cin>>x;
        while(t --)
            s += x;
    }

    vector<int> a(s.size());
    for(int i = 0;i < s.size();i++)
        a[i] = s[i] - '0';

    st.reset(a);
}

void solve()
{
    char c;
    int i, j, q, iter = 1;
    cin>>q;

    while(q--)
    {
        cin>>c>>i>>j;

        if(c == 'F')
            st.update(i, j, 1);
        else if(c == 'E')
            st.update(i, j, 2);
        else if(c == 'I')
            st.update(i, j, 3);
        else
        {
            printf("Q%d: %d\n", iter, st.rsq(i, j));
            iter ++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin>>tc;

    for(int i = 1;i <= tc;i++)
    {
        read();
        printf("Case %d:\n", i);
        solve();
    }
    return 0;
}