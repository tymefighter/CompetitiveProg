#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;


long int topDown(const vector<int> &w, const vector<long int> &p, vector<vector<long int> > &dp, int i, int s)
{
	if(i >= w.size() || s == 0)
		return 0;
	
	if(dp[i][s] == -1)
	{
		if(s - w[i] >= 0)
			dp[i][s] = max(topDown(w, p, dp, i+1, s), topDown(w, p, dp, i+1, s - w[i]) + p[i]);
		else
			dp[i][s] = topDown(w, p, dp, i+1, s);

	}
	
	return dp[i][s];
}

int main()
{
	int n, W;
	vector<long int> p;
	vector<int> w;
	vector<vector<long int> > dp;

	cin>>n>>W;

	p.resize(n);
	w.resize(n);
	dp.resize(n);

	for(int i = 0;i < n;i++)
	{
		cin>>w[i]>>p[i];
		dp[i].assign(W+1, -1);
	}

	
	cout<<topDown(w, p, dp, 0, W)<<'\n';

	return 0;
}
