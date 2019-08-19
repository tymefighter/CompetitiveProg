#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>

using namespace std;

vector<vector<int> > dp;
vector<vector<pair<int, bool> > > ans;
int n;

int solve(int x, int i)
{
	if(x < 0)
		return -10000000;

	if(dp[x][i] >= 0)
		return dp[x][i];
	
	if(i == 0 || x == 0)
	{
		dp[x][i] = 0;
		return 0;
	}
	
	int val1 = solve(x, i-1);
	int val2 = solve(x-i, i-1) + 1;
	
	if(val1 > val2)
	{
		dp[x][i] = val1;
		ans[x][i] = make_pair(x, false);
	}
	else
	{
		dp[x][i] = val2;
		ans[x][i] = make_pair(x-i, true);
	}

	return dp[x][i];
}

int main()
{
	int x, i;
	cin>>n;
	dp.resize(n+1);
	ans.resize(n+1);

	for(i = 0;i <= n;i++)
	{
		dp[i].assign(n+1, -1);
		ans[i].assign(n+1, {-1, false});
	}
	
	cout<<solve(n, n)<<'\n';
	
	x = i = n;
	while(i >= 0 && x >= 0 && ans[x][i].first >= 0)
	{
		if(ans[x][i].second)
			cout<<i<<" ";
		x = ans[x][i].first;
		i--;
	}

	cout<<'\n';
	return 0;
}
