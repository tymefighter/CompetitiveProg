#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

vector<long int> d{1, 5, 10, 20, 100};
vector<long int> dp;

long int solve(long int x)
{

	if(dp[x] >= 0)
		return dp[x];
	
	if(x == 0)
	{
		dp[x] = 0;
		return 0;
	}
	
	long int min_val = -1;

	for(long int y : d)
	{
		if(x-y >= 0)
		{
			if(min_val == -1)
				min_val = solve(x-y)+1;
			else
				min_val = min(min_val, solve(x-y) + 1);
		}
		//cout<<min_val<<'\n';
	}

	dp[x] = min_val;
	return dp[x];
}

int main()
{
	long int n;
	long int count = 0;

	cin>>n;

	if(n > 100)
	{
		count = (n / 100);
		n = n - (n / 100) * 100;	
	}
	
	dp.assign(n+1, -1);
	//cout<<n<<'\n';
	cout<<count + solve(n)<<'\n';
	return 0;
}
