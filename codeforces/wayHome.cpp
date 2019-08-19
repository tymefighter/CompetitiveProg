#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

vector<int> dp;
string s;

int solve(int n, int d)
{
	int i, j, val;

	dp[1] = 0;
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= d;j++)
		{
			if(i-j > 0 && s[i-1] == '1' && s[i-j-1] == '1')
			{
				if(dp[i-j] != -1)
					val = dp[i-j] + 1;
				else
					val = -1;
				if(dp[i] == -1 || val < dp[i])
					dp[i] = val;
			}
		}
	}

	return dp[n];
}

int main()
{
	int n, d;
	
	cin>>n>>d;
	cin>>s;

	dp.assign(n+1, -1);
	cout<<solve(n, d)<<'\n';
	return 0;
}
