#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

string s, ss;
int starti, endi;
vector<vector<int> > a(52);

bool small(char x)
{
	if(x >= 'a' && x <= 'z')
		return true;
	else
		return false;
}

void create_vec()
{
	for(int i = 0;i < s.size();i++)
	{
		if(small(s[i]))
			a[s[i] - 'a'].push_back(i);
		else
			a[s[i] - 'A' + 26].push_back(i);
	}
}

int smallest_larger(int i, int x)
{
	if(a[i][0] > x)	// first idx satisfies the condition
		return a[i][0];
	
	if(a[i][a[i].size()-1] <= x) // no such value
		return -1;

	int low = 0, high = a[i].size() - 1, mid;

	mid = (low + high) / 2;

	while(low <= high)
	{
		if(mid > 0 && a[i][mid] > x && a[i][mid-1] <= x)
			return a[i][mid];

		if(mid > 0 && a[i][mid-1] > x)
			high = mid - 1;
		else if(a[i][mid] <= x)
			low = mid + 1;

		mid = (low + high) / 2;
	}

	return -2;
}

bool solve()
{
	int idx = -1, count = 0;
	
	for(char c : ss)
	{
		if(small(c))
			idx = smallest_larger(c - 'a', idx);
		else
			idx = smallest_larger(c - 'A' + 26, idx);

		if(idx < 0)
			return false;
		
		if(count == 0)
		{
			starti = idx;
			endi = idx;
		}
		else if(count == ss.size()-1)
			endi = idx;

		count++;
	}

	return true;
}

int main()
{
	int q;
	cin>>s;
	create_vec();
	cin>>q;

	while(q--)
	{
		cin>>ss;
		if(solve())
			printf("Matched %d %d\n", starti, endi);
		else
			printf("Not matched\n");
	}

	return 0;
}


