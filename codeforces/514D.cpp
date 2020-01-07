#include<iostream>
#include<cmath>

using namespace std;

const int N = 100005, ST = 20;
int n, m, k, a[N][5], max_st[5][N][ST];

void build_st()
{
    int k, i, j;

    for(k = 0;k < m;k++)
    {
        for(i = 0;i < n;i++)
            max_st[k][i][0] = a[i][k];
        
        for(j = 1;(1 << j) <= n;j++)
        {
            for(i = 0;i + (1 << j) <= n;i++)
                max_st[k][i][j] = max(max_st[k][i][j - 1], max_st[k][i + (1 << (j - 1))][j - 1]);
        }
    }
}

int wp[5];

long long getCost(int l, int r)
{
    long long cost_val = 0;
    int j = (int)log2(r - l + 1);

    for(int k = 0;k < m;k++)
    {
        wp[k] = max(max_st[k][l][j], max_st[k][r - (1 << j) + 1][j]);
        cost_val += wp[k];
    }

    return cost_val;
}

void read()
{
    cin>>n>>m>>k;

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
            cin>>a[i][j];
    }

    build_st();
}

int b_search(int l)
{
    int low = l, high = n - 1, mid;

    if(getCost(l, high) <= k)
        return high;
    
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(mid < n - 1 && getCost(l, mid) <= k && getCost(l, mid + 1) > k)
            return mid;
        else if(mid < n - 1 && getCost(l, mid + 1) <= k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int wp_ans[5];

void solve()
{
    int ans_len = -1;

    for(int k = 0;k < m;k++)
        wp_ans[k] = 0;

    for(int l = 0;l < n;l++)
    {
        int r = b_search(l);
        
        if(r != -1 && ans_len < (r - l + 1))
        {
            ans_len = r - l + 1;
            
            (void)getCost(l, r);
            for(int k = 0;k < m;k++)
                wp_ans[k] = wp[k];
        }
    }
    
    for(int k = 0;k < m;k++)
        cout<<wp_ans[k]<<" ";
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}