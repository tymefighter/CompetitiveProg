#include<iostream>
#include<cmath>

using namespace std;

int r, n;

int solve()
{
    if(n == 0)
        return -1;

    int x = (int)ceil((float)r / n) - 1;

    if(x > 26)
        return -1;
    
    return x;
}

int main()
{
    int ans, cn = 1;
    while(cin>>r>>n)
    {
        if(!(r | n))
            break;
        ans = solve();
        
        if(ans < 0)
            printf("Case %d: impossible\n", cn);
        else
            printf("Case %d: %d\n", cn, ans);
        cn++;
    }
    return 0;
}