#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int bottomUp(vector<int> &h, int k)
{
	int min = 0, i, j, n = h.size() - 1;
	vector<int> dp(h.size());
	dp[n] = 0;

	for(i = n-1;i >= 1;i--)
	{
		min = -1;
		for(j = 1;j <= k;j++)
		{
			if(i+j > n)
				break;

			if(min == -1 || (dp[i + j] + abs(h[i] - h[i+j]) < min))
			{
				min = dp[i + j] + abs(h[i] - h[i+j]);
			}
		}

		dp[i] = min;
	}

	return dp[1];
}

int main()
{
	int n, k;

	cin>>n>>k;
	vector<int> h(n+1);

	for(int i = 1;i <= n;i++)
		cin>>h[i];

	cout<<bottomUp(h, k)<<'\n';
	return 0;
}
