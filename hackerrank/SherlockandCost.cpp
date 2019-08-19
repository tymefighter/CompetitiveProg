#include<iostream>

using namespace std;

int n;
int dp[100001][2];
int b[100001];

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>b[i];
}

int solve()
{
    int i, flag, flag2, max_val;
    dp[0][1] = dp[0][0] = 0;

    for(i = 1;i < n;i++)
    {
        for(flag = 0;flag < 2;flag++)
        {
            max_val = 0;
            for(flag2 = 0;flag2 < 2;flag2++)
                max_val = max(max_val, dp[i-1][flag2] + abs((flag == 1 ? b[i] : 1) - (flag2 == 1 ? b[i-1] : 1)));
            dp[i][flag] = max_val;
        }
    }

    return max(dp[n-1][0], dp[n-1][1]);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        cout<<solve()<<"\n";
    }

    return 0;
}