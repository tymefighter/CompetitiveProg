#include<cstdio>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> given(8), pos(8);
set<vector<int> > s;

void place_in_set()
{
	s.insert(pos);
}

bool place_allowed(int r, int c)
{
	for(int c_d = 0;c_d < c;c_d++)
	{
		if((r == pos[c_d])||(abs(r - pos[c_d]) == abs(c - c_d)))
			return false;
	}

	return true;
}

void solve(int c)
{

	if(c == 8)
	{
		place_in_set();
		return;
	}

	for(int r = 0;r < 8;r++)
	{
		if(place_allowed(r, c))
		{
			pos[c] = r;
			solve(c+1);
		}
	}

	return;
}

int dist(vector<int> x)
{

	int dist_val = 0;
	for(int i = 0;i < 8;i++)
	{
		dist_val += (x[i] == given[i] ? 0 : 1);
	}

	return dist_val;
}

int find_min()
{
	int ans = -1, val;
	for(auto x : s)
	{
		val = dist(x);
		if(ans == -1 || val < ans)
		{
			ans = val;
		}
	}

	return ans;
}

int main()
{
	int i, count = 1, ct = 1;

	solve(0);

	while(cin>>given[0])
	{
		given[0]--;
		for(i = 1;i < 8;i++)
		{
			cin>>given[i];
			given[i]--;
		}
		printf("Case %d: %d\n", ct, find_min());
		ct++;
	}
	return 0;
}
