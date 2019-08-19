#include<iostream>

using namespace std;

int n;
long long int k;
long long int dp[105][105], prev_i[105];
char a[105];

void reset()
{
    int i, j;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= n;j++)
        {
            if(j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    dp[0][1] = 1;

    for(i = 0;i < n;i++)
    {
        j = i - 1;
        while(j >= 0 && a[j] != a[i])
            j--;
        prev_i[i] = j;
    }
}

void read()
{
    cin>>n>>k;
    for(int i = 0;i < n;i++)
        cin>>a[i];

    reset();
}

void solve()
{
    int id, length;
    long long int val;
    for(id = 1;id < n;id++)
    {
        for(length = 1;length <= id + 1;length++)
        {
            if(prev_i[id] > 0)
                val = dp[prev_i[id] - 1][length - 1];
            else if(prev_i[id] == 0 && length == 1)
                val = 1;
            else
                val = 0;
            dp[id][length] = dp[id - 1][length] + dp[id - 1][length - 1] - val;
        }
    }

    long long int no = 0, ans = 0;


    for(length = n;length >= 0;length--)
    {
        val = dp[n - 1][length];
        if(no + val >= k)
        {
            ans += (k - no) * (n - length);
            cout<<ans<<"\n";
            return;
        }

        no += val;
        ans += val * (n - length);
    }

    cout<<"-1\n";
}

int main()
{
    read();
    solve();
    return 0;
}