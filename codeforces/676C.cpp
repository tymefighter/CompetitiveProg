#include<iostream>

using namespace std;

/*
    Two pointer method (l .. r)
*/

int n, k;
char a[100005];

void read()
{
    cin>>n>>k;
    for(int i = 0;i < n;i++)
        cin>>a[i];
}

void solve()
{
    int l, r, kc, ans = 0;
    // 1 - substring with all a's
    l = r = 0;
    kc = k;
    while(r < n)
    {
        while(r < n && kc >= 0)
        {
            if(a[r] == 'b')
                kc--;
            if(kc < 0)
            {
                kc = 0;
                break;
            }
            r++;
        }
        ans = max(ans, r - l);
        if(a[l] == 'b')
            kc++;
        l++;
    }
    // 2 - substring with all b's
    l = r = 0;
    kc = k;
    while(r < n)
    {
        while(r < n && kc >= 0)
        {
            if(a[r] == 'a')
                kc--;
            if(kc < 0)
            {
                kc = 0;
                break;
            }
            r++;
        }
        ans = max(ans, r - l);
        if(a[l] == 'a')
            kc++;
        l++;
    }
    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}