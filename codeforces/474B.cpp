#include<iostream>

using namespace std;

int a[100005];
int n;

void read()
{
    int x, cu;
    cin>>n;
    a[0] = 1;
    cu = 1;

    for(int i = 1;i <= n;i++)
    {
        cin>>x;
        cu += x;
        a[i] = cu;
    }

    n++;
}

int b_search(int x)
{
    int low = 0, high = n-1, mid;
    mid = (low + high) / 2;

    while(low <= high)
    {
        if(mid < n-1 && a[mid] <= x && a[mid + 1] > x)
            return mid;
        else if(mid < n-1 && a[mid + 1] <= x)
            low = mid + 1;
        else
            high = mid - 1;

        mid = (low + high) / 2;
    }

    return -1;
}

void solve()
{
    int m, x;
    cin>>m;

    for(int i = 0;i < m;i++)
    {
        cin>>x;
        cout<<b_search(x) + 1<<"\n";
    }
}

int main()
{
    read();
    solve();

    return 0;
}
