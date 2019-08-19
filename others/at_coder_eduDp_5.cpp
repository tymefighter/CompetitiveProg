#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<utility>

using namespace std;

/*
long int topDown(const vector<long int> &w, const vector<long int> &p, map<pair<long int, long int>, long int> dp, pair<long int, long int> b)
{
	if(b.first >= w.size() || b.second == 0)
		return 0;
	
	if(dp.find(b) == dp.end())
	{
		if(b.second - w[b.first] >= 0)
			dp[b] = max(topDown(w, p, dp, make_pair(b.first+1, b.second)), topDown(w, p, dp, make_pair(b.first+1, b.second - w[b.first])) + p[b.first]);
		else
			dp[b] = topDown(w, p, dp, make_pair(b.first+1, b.second));
	}
	
	return dp[b];
}*/

long int bottomUp(const vector<int> &w, const vector<int> &w, vector<vector<int> >dp, int W)
{
	//n-1
	dp[0][W] = 
}

int main()
{
	long int n, W;
	vector<long int> p;
	vector<long int> w;
	vector<vector<int> > dp(2);

	cin>>n>>W;

	p.resize(n);
	w.resize(n);
	dp[0].assign(W+1, -1);
	dp[1].assign(W+1, -1);


	for(int i = 0;i < n;i++)
	{
		cin>>w[i]>>p[i];
	}
	
	cout<<bottomUp(w, p, dp, W)<<'\n';



	return 0;
}

