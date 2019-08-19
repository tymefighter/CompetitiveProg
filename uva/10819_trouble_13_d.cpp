#include<iostream>

using namespace std;

int dp[102][10502];
int f[102], p[102];
int M, n;
bool check;

void read()
{
    int i, j;
    for(i = 0;i <= n;i++)
    {
        if(i)
            cin>>p[i]>>f[i];

        for(j = 0;j <= M + 250;j++)
            dp[i][j] = -1;
    }
}

int solve(int i, int m)
{
    if(m < 0)
        return -1;

    if(dp[i][m] != -1)
        return dp[i][m];
    
    if(i == 0 || m == 0)
    {

        int spent = M + 200 - m;

        if(spent > M && spent <= 2000)
            return -1;

        return 0;
    }
    
    int val1 = solve(i - 1, m);
    int val2 = solve(i - 1, m - p[i]);


    if(val1 == -1 && val2 == -1)
        dp[i][m] =  -1;
    else if(val2 == -1)
        dp[i][m] = val1;
    else if(val1 == -1)
        dp[i][m] =  val2 + f[i];
    else
        dp[i][m] =  max(val1, val2 + f[i]);

    return dp[i][m];
}

int main()
{
    int val;
    while(cin>>M>>n)
    {
        read();
        cout<<solve(n, M + 200);
        cout<<"\n";
    }
    return 0;
}