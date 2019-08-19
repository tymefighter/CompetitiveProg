#include<iostream>
#include<string>

using namespace std;

int n;
int dp[200005];
int pre[3];
string s;

void reset()
{
    for(int i = 0;i <= n;i++)
        dp[i] = -1;
    
    for(int i = 0;i < 3;i++)
        pre[i] = -1;
}

void read()
{
    cin>>s;
    n = s.size();
    reset();
}

void solve()
{
    int rem_sum = 0;
    dp[0] = 0;

    for(int i = 1;i <= n;i++)
    {
        rem_sum = (rem_sum + (s[i - 1] - '0')) % 3;

        if(pre[rem_sum] == -1 && rem_sum != 0)
            dp[i] = dp[i - 1];
        else
            dp[i] = max(dp[i - 1], dp[pre[rem_sum] + 1] + 1);
        
        pre[rem_sum] = i - 1;
    }

    cout<<dp[n]<<"\n";
}


int main()
{
    read();
    solve();
    return 0;
}