#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<string>
#include<stack>

using namespace std;


vector<vector<pair<int, int> > > bottomUp(const string &a, const string &b)
{
	int n = a.size(), m = b.size(), i, j;

	vector<vector<int> > dp(n);
	vector<vector<pair<int, int> > > pred(n);


	for(i = 0;i < n;i++)
	{
		dp[i].resize(m);
		pred[i].resize(m);
		for(j = 0;j < m;j++)
		{
			if(i == 0 && j == 0)
			{
				dp[i][j] = (a[i] == b[j] ? 1 : 0);
				pred[i][j].first = -1;
				pred[i][j].second = -1;
			}
			else if(i == 0)
			{
				if(a[i] == b[j])
				{
					dp[i][j] = 1;
					pred[i][j].first = -1;
					pred[i][j].second = j-1;
				}
				else
				{
					dp[i][j] = dp[i][j-1];
					pred[i][j].first = 0;
					pred[i][j].second = j-1;
				}
			}
			else if(j == 0)
			{
				if(a[i] == b[j])
				{
					dp[i][j] = 1;
					pred[i][j].first = i-1;
					pred[i][j].second = -1;
				}
				else
				{
					dp[i][j] = dp[i-1][j];
					pred[i][j].first = i-1;
					pred[i][j].second = 0;
				}
			}
			else
			{
				if(a[i] == b[j])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
					pred[i][j].first = i-1;
					pred[i][j].second = j-1;
				}
				else
				{
					if(dp[i][j-1] > dp[i-1][j])
					{
						dp[i][j] = dp[i][j-1];
						pred[i][j].first = i;
						pred[i][j].second = j-1;
					}
					else
					{
						dp[i][j] = dp[i-1][j];
						pred[i][j].first = i-1;
						pred[i][j].second = j;
					}

				}
			}
		}
	}
	return pred;
}

int main()
{
	string a, b;
	cin>>a>>b;

	vector<vector<pair<int, int> > > pred = bottomUp(a, b);
	pair<int, int> x;

	x.first = a.size() - 1;
	x.second = b.size() - 1;


	stack<char> st;
	while(x.first != -1 && x.second != -1)
	{
		if(a[x.first] == b[x.second])
			st.push(a[x.first]);

		x = pred[x.first][x.second];

	}

	while(st.empty() == false)
	{
		cout<<st.top();
		st.pop();
	}
	return 0;
}
