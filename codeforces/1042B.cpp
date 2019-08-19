#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;
int p[1002], v[1002], dp[1002][8];

int solve(int i, int choice)
{
    
    if(i == 0 && choice != (1 << 3) - 1)
        return -1;
    
    if(dp[i][choice] != -1)
        return dp[i][choice];
    
    if(choice == (1 << 3) - 1)
    {
        dp[i][choice] = 0;
        return dp[i][choice];
    }

    int val1 = solve(i-1, choice);
    int val2;
    if((choice | v[i]) == choice) // pruning
        val2 = val1;
    else
        val2 = solve(i-1, choice | v[i]);




    if(val2 == -1)
        dp[i][choice] = val1;
    else if(val1 == -1)
        dp[i][choice] = val2 + p[i];
    else
        dp[i][choice] = min(val1, val2 + p[i]);

    return dp[i][choice];
}

int main()
{
    int i, j;
    string s;
    cin>>n;

    for(j = 0;j < 8;j++)
        dp[0][j] = -1;

    for(i = 1;i <= n;i++)
    {
        cin>>p[i]>>s;
        sort(s.begin(), s.end());
        v[i] = 0;
        for(char x : s)
        {
            if(x == 'A')
                v[i] |= 1;
            else if(x == 'B')
                v[i] |= (1 << 1);
            else
                v[i] |= (1 << 2);
        }
        //cout<<v[i]<<"--\n";
        for(j = 0;j < 8;j++)
            dp[i][j] = -1;
    }

    cout<<solve(n, 0)<<'\n';

    return 0;
}