#include<iostream>
#define MIN -100000000

using namespace std;

// 0: stay, 1: left, 2: right
int n;
long long int x[100005], h[100005];
int dp[100005][3];

void read()
{
    cin>>n;
    for(int i = 1;i <= n;i++)
        cin>>x[i]>>h[i];
}

void solve()
{
    dp[1][0] = 0;
    dp[1][1] = dp[1][2] = 1;

    int i;
    for(i = 2;i <= n;i++)
    {
        // 0
        dp[i][0] = MIN;
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if(x[i] - (x[i - 1] + h[i - 1]) > 0)
            dp[i][0] = max(dp[i][0], dp[i - 1][2]);

        // 1
        dp[i][1] = MIN;
        if((x[i] - h[i]) - x[i - 1] > 0)
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        if((x[i] - h[i]) - (x[i - 1] + h[i - 1]) > 0)
            dp[i][1] = max(dp[i][0], dp[i - 1][2] + 1);

        // 2
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        if(x[i] - (x[i - 1] + h[i - 1]) > 0)
            dp[i][2] = max(dp[i][0], dp[i - 1][2] + 1);
    }

    cout<<max(dp[n][0], max(dp[n][1], dp[n][2]))<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}