#include<iostream>
#include<vector>
#include<map>

using namespace std;

int n, q, a[100005];
vector<int> tree;
map<int, int> m_left, m_right;

void reset()
{
    tree.clear();
    m_left.clear();
    m_right.clear();
}

void read()
{   
    reset();
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        if(m_left.find(a[i]) == m_left.end())
            m_left[a[i]] = i;
        
        m_right[a[i]] = i;
    }

    tree.assign(4 * n, -1);
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
        tree[p] = 1;
        return;
    }
    int mid = (L + R) / 2;
    
    build(left(p), L, mid);
    build(right(p), mid + 1, R);

    tree[p] = max(tree[left(p)], tree[right(p)]);

    if(a[mid] == a[mid + 1])
        tree[p] = max(tree[p], min(m_right[a[mid]], R) - max(m_left[a[mid]], L) + 1);
}

int rfq(int p, int L, int R, const int &i, const int &j)
{
    if(i > R || j < L)
        return 0;
    
    if(i <= L && R <= j)
        return tree[p];
    
    int mid = (L + R) / 2;
    int ans = max(rfq(left(p), L, mid, i, j), rfq(right(p), mid + 1, R, i, j));

    if(a[mid] == a[mid + 1])
        ans = max(ans, min(m_right[a[mid]], j) - max(m_left[a[mid]], i) + 1);
    

    return ans;
}

void solve()
{
    int i, j;
    while(q--)
    {
        cin>>i>>j;
        i--, j--;
        cout<<rfq(1, 0, n - 1, i, j)<<"\n";
    }
}

int main()
{
    while(cin>>n)
    {
        if(!n)
            break;
        cin>>q;
        read();
        build(1, 0, n - 1);
        solve();
    }
    
    return 0;
}