#include<iostream>
#include<algorithm>

using namespace std;

int a[1001], b[1001];
int B, n, m;

void read()
{
    cin>>B>>n>>m;

    for(int i = 0;i < n;i++)
        cin>>a[i];
    
    for(int i = 0;i < m;i++)
        cin>>b[i];
    
    sort(b, b+m);

}

int b_search(int x)
{
    if(x < 0)
        return -1;
    
    if(x >= b[m-1])
        return b[m-1];

    int low = 0, high = m-1, mid;

    mid = (low + high) / 2;

    while(low <= high)
    {
        if(mid < m-1 && b[mid] <= x && b[mid+1] > x)
        {
            return b[mid];
        }
        else if(mid < m-1 && b[mid + 1] <= x)
        {
            low = mid + 1;
        }
        else if(b[mid] > x)
        {
            high = mid - 1;
        }

        mid = (low  + high) / 2;
    }

    return -1;
}

void solve()
{
    int val, max_val;
    val = max_val = -1;
    for(int i = 0;i < n;i++)
    {
        val = b_search(B - a[i]);
        if(val >= 0)
        {
            val += a[i];
            if(val > max_val)
                max_val = val;
        }
    }

    cout<<max_val<<"\n";
}

int main()
{
    read();
    solve();

    return 0;
}