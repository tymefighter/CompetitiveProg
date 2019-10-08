#include<iostream>

using namespace std;

int n, m, L, U;
int a[505][505];

void read()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
            cin>>a[i][j];
    }
}

int b_search(int row, int val)
{
    int low = 0, high = m - 1, mid;
    mid = (low + high) / 2;

    if(a[row][low] >= val)
        return low;

    while(low <= high)
    {
        if(mid > 0 && a[row][mid - 1] < val && a[row][mid] >= val)
            return mid;
        else if(mid > 0 && a[row][mid - 1] >= val)
            high = mid - 1;
        else
            low = mid + 1;

        mid = (low + high) / 2;
    }

    return -1;
}

void solve()
{
    int ans = 0, row, col, size;

    for(row = 0;row < n;row++)
    {
        col = b_search(row, L);
        if(col == -1)
            continue;
        
        for(size = ans + 1;size <= n;size++)
        {
            if(row + size - 1 >= n || col + size - 1 >= m || a[row + size - 1][col + size - 1] > U)
                break;
        }

        ans = max(ans, size - 1);
    }

    cout<<ans<<"\n";
}

void query()
{
    int q;
    cin>>q;

    while(q--)
    {
        cin>>L>>U;
        solve();
    }
    cout<<"-\n";
}

int main()
{
    while(cin>>n>>m)
    {
        if(!(n | m))
            break;
        read();
        query();
    }
    return 0;
}