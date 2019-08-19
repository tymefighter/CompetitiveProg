#include<iostream>
#include<string>

using namespace std;

string s;
long long int dp[17][17];
int n;

void reset()
{
    int i, j;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= n;j++)
            dp[i][j] = -1ll;
    }
}

long long int count(int c, int prev_r)
{
    if(c == n)
        return 1ll;

    if(dp[c][prev_r] != -1)
        return dp[c][prev_r];

    int start, end;
    if(s[c] != '?')
    {
        start = max(prev_r - 1, 1);
        end = min(prev_r + 1, n);

        int row;
        
        if(s[c] >= '1' && s[c] <= '9')
            row = s[c] - '0';
        else
            row = s[c] - 'A' + 10;

        if(!(start <= row && row <= end) || prev_r == 0)
            dp[c][prev_r] = count(c + 1, row);
        else
            dp[c][prev_r] = 0;
        return dp[c][prev_r];
    }
    
    long long int ans = 0ll;
    if(prev_r == 0)
    {
        for(int r = 1;r <= n;r++)
            ans += count(c + 1, r);

        dp[c][prev_r] = ans;
        return ans;
    }

    start = max(prev_r - 1, 1); // not allowed region
    end = min(prev_r + 1, n);

    for(int r = 1;r <= n;r++)
    {
        if(r >= start && r <= end)
            continue;
        ans += count(c + 1, r);
    }

    dp[c][prev_r] = ans;
    return ans;
}

int main()
{
    while(cin>>s)
    {
        n = s.size();
        reset();
        cout<<count(0, 0)<<"\n";
    }
    
    return 0;
}