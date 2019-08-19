#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<vector<char> > a;
vector<vector<vector<int> > >dp;
vector<int> leftmost, rightmost;

int n, m;


void read()
{
	cin>>n>>m;
	a.resize(n+1);
	dp.resize(n+1);
	leftmost.resize(n+1);
	rightmost.resize(n+1);
	bool flag;
	int i, j, h = -1;
	
	//cout<<m<<'\n';
	for(i = n;i >= 0;i--)
	{
		a[i].resize(m+2);
		dp[i].resize(2);
		for(j = 0;j < 2;j++)
			dp[i][j].resize(2);
		
		if(i == 0)
			continue;
		
		flag = false;
		for(j = 0;j <= m+1;j++)
		{
			cin>>a[i][j];
			
			if(flag == false && a[i][j] == '1')
			{
				leftmost[i] = j;
				flag = true;
				
				if(h == -1)
					h = i;
				//cout<<i<<'\n';
			}
			
			if(a[i][j] == '1')
			{
				rightmost[i] = j;
			}
		}
		//cout<<leftmost[i]<<'\n';
	}
	
	n = h;
	//cout<<n<<'\n';
}

void solve()
{
	int i, j, k, r;

	for(j = 0;j < 2;j++)
	{
		for(k = 0;k < 2;k++)
		{
			if(k == 1)
				dp[0][j][k] = 100000000;
			else
				dp[0][j][k] = 0;
		}
	}
	
	for(i = 1;i <= n-1;i++) // row
	{
		for(j = 0;j < 2;j++) // entry
		{
			for(k = 0;k < 2;k++) // exit
			{
				dp[i][j][k] = 100000000;
				for(r = 0;r < 2;r++) // entry for lower level
				{
					if(j != k) // entry != exit
					{
						if(i != 1)
							dp[i][j][k] = min(dp[i][j][k], dp[i-1][r][j] + m + 1 + 1);
						else
							dp[i][j][k] = min(dp[i][j][k], dp[i-1][r][j] + m + 1);
					}
					else
					{
						if(j == 0)
						{
							if(i != 1)
								dp[i][j][k] = min(dp[i][j][k], dp[i-1][r][j] + 2*rightmost[i] + 1);
							else
								dp[i][j][k] = min(dp[i][j][k], dp[i-1][r][j] + 2*rightmost[i]);
						}
						else
						{
							if(leftmost[i] != 0)
							{
								if(i != 1)
									dp[i][j][k] = min(dp[i][j][k], dp[i-1][r][j] + 2*(m+1 - leftmost[i]) + 1);
								else
									dp[i][j][k] = min(dp[i][j][k], dp[i-1][r][j] + 2*(m+1 - leftmost[i]));
							}
							else
							{
								if(i != 1)
									dp[i][j][k] = min(dp[i][j][k], dp[i-1][r][j]+ 1);
								else
									dp[i][j][k] = min(dp[i][j][k], dp[i-1][r][j]);
							}	
							//if(i != 1)
								//printf("%d %d %d %d %d %d %d %d\n", i, j, k, r, leftmost[i], m+1, dp[i-1][r][j], dp[i][j][k]);
						}
					}
				}
			}
		}
	}
	
	if(n == -1)
	{
		cout<<0<<'\n';
		return;
	}
	
	
	int ans = 100000000;
	for(j = 0;j < 2;j++)
	{
		for(r = 0;r < 2;r++)
		{
			if(j == 0)
			{
				if(n != 1)
					ans = min(ans, dp[n-1][r][j] + rightmost[n] + 1);
				else
					ans = min(ans, dp[n-1][r][j] + rightmost[n]);
			}
			else
			{
				if(n != 1)
					ans = min(ans, dp[n-1][r][j] + (m+1 - leftmost[n]) + 1);
				else
					ans = min(ans, dp[n-1][r][j] + rightmost[n]);
			}
		}
	}
	cout<<ans<<'\n';
	return;
}

int main()
{
	read();	
	solve();
	
	//for(int i = 1;i < n;i++)
		//printf("%d %d %d %d\n", dp[i][0][0], dp[i][0][1], dp[i][1][0], dp[i][1][1]);
	
	return 0;
}
