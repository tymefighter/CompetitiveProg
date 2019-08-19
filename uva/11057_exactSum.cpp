#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int a, b;
int bk_c[10002];

void read()
{
    for(int i = 0;i < n;i++)
        cin>>bk_c[i];
    cin>>m;
}

bool binary_search(int x, int idx)
{
    int low = 0, high = n-1, mid;
    mid = (low + high) / 2;
    while(low <= high)
    {
        if(bk_c[mid] == x)
        {
            if(mid != idx)
                return true;
            if(idx != 0 && bk_c[mid-1] == x)
                return true;
            if(idx != n-1 && bk_c[mid+1] == x)
                return true;
            return false;
        }
        if(bk_c[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
        
        mid = (low + high) / 2;
    }

    return false;
}

void solve()
{
    sort(bk_c, bk_c+n);
    int val;

    for(int i = 0;i < n;i++)
    {
        val = m - bk_c[i];

        if(val > 0 && binary_search(val, i) == true)
        {
            if(a == -1 || abs(bk_c[i] - val) < abs(a - b))
            {
                a = bk_c[i];
                b = val;
            }
        }
    }
}

int main()
{
    while(cin>>n)
    {
        a = b = -1;
        read();
        solve();
        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }
    return 0;
}