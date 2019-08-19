#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>

using namespace std;

vector<pair<int, pair<int, int> > >a, alb;
vector<int> b;
vector<vector<int> >dp;

int solve(int i, int p, int j)
{
	//printf("%d %d %d %d\n",i, p, j, dp[i].size());
	if(p < 0)
		return -100000000;

	//printf("%d %d %d\n", i, p, dp[i][p]);

	if(dp[i][p] != -1)
		return dp[i][p];
	
	if(i == 0 || p == 0)
	{
		dp[i][p] = 0;
		return 0;
	}

	int val1, val2;
		
	if(j > 0 && i == alb[j].first)
	{
		val1 = solve(i-1, p, j-1);
		val2 = solve(i-1, p - a[i].second.first, j-1) + a[i].second.second;
		int val3 = solve(alb[j-1].first, p - alb[j].second.first, j-1) + alb[j].second.second;
		
		
		dp[i][p] = max(max(val1, val2), val3);
		//printf("%d %d %d %d %d %d\n", i, p, val1, val2, val3, dp[i][p]);	
		return dp[i][p];
	}
	
	//printf("n: %d i: %d %d %d\n", a.size()-1, i, val1, val2);
	val1 = solve(i-1, p, j);
	val2 = solve(i-1, p - a[i].second.first, j) + a[i].second.second;
	dp[i][p] = max(val1, val2);
	return dp[i][p];
}

int main()
{
	int n, m, p, i, gr = 0;
		
	cin>>n>>m>>p;

	a.resize(n+1);
	dp.resize(n+1);
	b.resize(m+1);
	
	for(i = 1;i <= n;i++)
	{
		dp[i].assign(p+1, -1);
		cin>>a[i].first>>a[i].second.first>>a[i].second.second;
	}
	dp[0].assign(p+1, -1);
	
	for(i = 1;i <= m;i++)
	{

		cin>>b[i];
	}

	sort(a.begin()+1, a.end());
	alb.push_back({0, {0, 0}});


	for(i = 1;i <= n-1;i++)
	{
		gr += a[i].second.second;
		if(a[i].first != a[i+1].first)
		{
			alb.push_back({i, {b[a[i].first], gr}});
			gr = 0;
		}
	}
	gr += a[n].second.second;
	alb.push_back({n, {b[a[n].first], gr}});
	
	//cout<<n<<'\n';
	cout<<solve(n, p, alb.size()-1)<<'\n';
	//cout<<alb.size()<<'\n';
	/*for(auto x : alb)
	{
		//for(auto y : x)
			//cout<<y<<" ";
		printf("%d %d %d\n", x.first, x.second.first, x.second.second);
	}

	for(auto x : dp)
	{
		for(auto y : x)
			cout<<y<<" ";
		cout<<'\n';
		//printf("%d %d %d\n", x.first, x.second.first, x.second.second);
	}*/
	//cout<<dp[3][11]<<'\n';
	return 0;
}

