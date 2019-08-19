#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int n, ans;
int loc[5], ans_loc[5];
vector<pair<pair<int, int>, int> > a;

int dist(int r1, int c1, int pt)
{
	int r2, c2;
	r2 = pt / 5;
	c2 = pt % 5;

	return abs(r1 - r2) + abs(c1 - c2);
}

void read()
{
	int r, c, val;
	cin>>n;
	a.clear();
	a.resize(n);

	for(int i = 0;i < n;i++)
	{
		cin>>a[i].first.first>>a[i].first.second>>a[i].second;
	}
}

int eval()
{
	int total = 0, u, v, min_dist, dist_val;

	for(u = 0;u < n;u++)
	{
		min_dist = -1;
		for(v = 0;v < 5;v++)
		{
			dist_val = dist(a[u].first.first, a[u].first.second, loc[v]);
			if(min_dist == -1 || dist_val < min_dist)
				min_dist = dist_val;
		}
		total += a[u].second * min_dist;
	}
	
	return total;
}

void solve()
{
	int min_dist, dist_val, total;
	int i, j, k, l, m, u, v;

	ans = -1;

	for(i = 0;i < 21;i++)
	{
		loc[0] = i;
		for(j = i+1;j < 22;j++)
		{
			loc[1] = j;
			for(k = j+1;k < 23;k++)
			{
				loc[2] = k;
				for(l = k+1;l < 24;l++)
				{
					loc[3] = l;
					for(m = l+1;m < 25;m++)
					{
						loc[4] = m;
						total = eval();
						if((ans == -1) || (total < ans))
						{
							ans = total;
							for(v = 0;v < 5;v++)
								ans_loc[v] = loc[v];
						}
					}
				}
			}
		}
	}
}

int main()
{
	int t, i;
	cin>>t;

	while(t--)
	{
		read();
		solve();
		for(i = 0;i < 5;i++)
		{
			if(i)
				cout<<" ";
			cout<<ans_loc[i];
		}
		cout<<'\n';
	}
	return 0;
}
