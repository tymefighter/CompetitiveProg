#include<iostream>

using namespace std;

long long int n, m, ans;
int is_white; // Is the bottom right corner white

void solve()
{

    if(is_white)
    {
        ans = (1 + (m - 8) / 2) * (1 + (n - 8) / 2);

        if(m > 8 && n > 8)
            ans += (1 + (m - 9) / 2) * (1 + (n - 9) / 2);
    }
    else
    {
        ans = 0;
        
        if(m > 8)
            ans += (1 + (m - 9) / 2) * (1 + (n - 8) / 2);
        if(n > 8)
            ans += (1 + (m - 8) / 2) * (1 + (n - 9) / 2);
    }

    cout<<ans<<"\n";
}

int main()
{
    while(cin>>n>>m>>is_white)
    {
        if(!(n | m | is_white))
            break;
        solve();
    }
    return 0;
}