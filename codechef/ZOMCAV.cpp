#include<iostream>
#include<algorithm>

using namespace std;

int n;
int c[100005], h[100005], a[100005];

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>c[i];
    for(int i = 0;i < n;i++)
        cin>>h[i];
}

bool solve()
{
    int i;
    for(i = 0;i <= n;i++)
        a[i] = 0;
    
    for(i = 0;i < n;i++)
    {
        a[max(i - c[i], 0)] += 1;
        a[min(i + c[i] + 1, n)] -= 1;
    }

    for(i = 1;i < n;i++)
        a[i] += a[i - 1];
    
    sort(a, a + n);
    sort(h, h + n);

    for(i = 0;i < n;i++)
    {
        if(a[i] != h[i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        if(solve())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}