#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<long int> dp;

long int fib(long int n)
{
	if(dp[n] >= 0)
		return dp[n];
	if(n == 0 || n == 1)
	{
		dp[n] = 1;
		return 1;
	}
	else
	{
		dp[n] = fib(n-1) + fib(n-1);
		return dp[n];
	}
}

int main()
{
	long int n;
	cin>>n;
	dp.assign(n+1, -1);
	cout<<fib(n)<<'\n';
}
