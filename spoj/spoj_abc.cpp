#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int solve(vector<vector<int> > &m, const vector<vector<char> > &a, int r, int c, const int &h, const int &w)
{
	int max_val = 0;

	if(m[r][c] != -1)
		return m[r][c];

	if(r-1 >= 0 && (a[r-1][c] - a[r][c] == 1))
		max_val = max(max_val, solve(m, a, r-1, c, h, w));

	if(r+1 < h && (a[r+1][c] - a[r][c] == 1))
		max_val = max(max_val, solve(m, a, r+1, c, h, w));

	if(c-1 >= 0 && (a[r][c-1] - a[r][c] == 1))
		max_val = max(max_val, solve(m, a, r, c-1, h, w));

	if(c+1 < w && (a[r][c+1] - a[r][c] == 1))
		max_val = max(max_val, solve(m, a, r, c+1, h, w));
	
	if(c-1 >= 0 && r-1 >= 0 && (a[r-1][c-1] - a[r][c] == 1))/////////
		max_val = max(max_val, solve(m, a, r-1, c-1, h, w));
	
	if(c+1 < w && r-1 >= 0 && (a[r-1][c+1] - a[r][c] == 1))/////////
		max_val = max(max_val, solve(m, a, r-1, c+1, h, w));
	
	if(c-1 >= 0 && r+1 < h && (a[r+1][c-1] - a[r][c] == 1))/////////
		max_val = max(max_val, solve(m, a, r+1, c-1, h, w));

	if(c+1 < w && r+1 < h  && (a[r+1][c+1] - a[r][c] == 1))/////////
		max_val = max(max_val, solve(m, a, r+1, c+1, h, w));
	
	m[r][c] = max_val + 1;

	return m[r][c];
}

int main()
{
	int h, w, i, j, max_val, count = 1;
	vector<vector<char> >a;
	vector<pair<int, int> > loc_a;
	vector<vector<int> > m;

	while(cin>>h>>w)
	{
		if(h == 0 && w == 0)
			break;

		a.clear();
		a.resize(h);
		m.clear();
		m.resize(h);
		loc_a.clear();
		max_val = 0;

		for(i = 0;i < h;i++)
		{
			a[i].resize(w);
			m[i].assign(w, -1);

			for(j = 0;j < w;j++)
			{
				cin>>a[i][j];
				if(a[i][j] == 'A')
				{
					loc_a.push_back(make_pair(i, j));
				}
			}
		}
	
		for(auto x : loc_a)
		{
			max_val = max(max_val, solve(m, a, x.first, x.second, h, w));
			//printf("%d %d\n",x.first, x.second);
		}
		printf("Case %d: %d\n", count, max_val);
		count++;
	}
	return 0;
}
