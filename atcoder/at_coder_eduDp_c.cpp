#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;



int bottomUp(const vector<vector<int> > w, vector<vector<int> > dp)
{
	int i, j, x, n, max_val;
	n = w.size();

	dp[0][0] = w[0][0];
	dp[0][1] = w[0][1];
	dp[0][2] = w[0][2];


	for(i = 1; i < n;i++)
	{
		max_val = 0;
		dp[i][0] = max(dp[i-1][1] + w[i][0], dp[i-1][2] + w[i][0]);
		dp[i][1] = max(dp[i-1][0] + w[i][1], dp[i-1][2] + w[i][1]);
		dp[i][2] = max(dp[i-1][0] + w[i][2], dp[i-1][1] + w[i][2]);
	}

	return max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
}


int main()
{
	int n;
	vector<vector<int> >w, dp;

	cin>>n;
	w.resize(n);
	dp.resize(n);

	for(int i = 0;i < n;i++)
	{
		w[i].resize(3);
		dp[i].resize(3);
		
		cin>>w[i][0]>>w[i][1]>>w[i][2];
	}

	cout<<bottomUp(w, dp)<<'\n';
	return 0;
}
