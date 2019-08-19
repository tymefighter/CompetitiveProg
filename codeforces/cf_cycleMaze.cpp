#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

stack<char> st;

bool solve(const vector<vector<char> > &a, int r, int c, int len, const int &k, const int &start_r, const int &start_c, const int &n, const int &m)
{

	if(len == k)
	{
		if(r+1 == start_r && c == start_c)
			st.push('D');
		else if(r == start_r && c-1 == start_c)
			st.push('L');
		else if(r == start_r && c+1 == start_c)
			st.push('R');
		else if(r-1 == start_r && c == start_c)
			st.push('U');
		else
			return false;

		return true;
	}

	if(r+1 < n && a[r+1][c] == '.')
	{
		if(solve(a, r+1, c, len+1, k, start_r, start_c, n, m))
		{
			st.push('D');
			return true;
		}
	}
	if(c-1 >= 0 && a[r][c-1] == '.')
	{
		if(solve(a, r, c-1, len+1, k, start_r, start_c, n, m))
		{
			st.push('L');
			return true;
		}
	}
	if(c+1 < m && a[r][c+1] == '.')
	{
		if(solve(a, r, c+1, len+1, k, start_r, start_c, n, m))
		{
			st.push('R');
			return true;
		}
	}
	if(r-1 >= 0 && a[r-1][c] == '.')
	{
		if(solve(a, r-1, c, len+1, k, start_r, start_c, n, m))
		{
			st.push('U');
			return true;
		}
	}

	
	return false;
}

int main()
{
	int n, m, k, i, j, r, c;

	cin>>n>>m>>k;

	vector<vector<char> >a(n);
	
	for(i = 0;i < n;i++)
	{
		a[i].resize(m);

		for(j = 0;j < m;j++)
		{
			cin>>a[i][j];
			if(a[i][j] == 'X')
			{
				r = i;
				c = j;
				a[i][j] = '.';
			}
		}
	}
	
	if(solve(a, r, c, 1, k, r, c, n, m))
	{
		while(st.empty() == false)
		{
			cout<<st.top();
			st.pop();
		}
		cout<<'\n';
	}
	else
		printf("IMPOSSIBLE\n");

	return 0;
}
