#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<vector<int> > dp;

int solve(int n, int v)
{
	if(v >= n-1)
		return n-1;
	
	int cost = v, i = 2;
	
	while(i != n)
	{
		cost += i;
		if(v == n-i)
			return cost;
		//cout<<i<<'\n';
		i++;
	}

	return cost;
}

int main()
{
	int n, v;
	
	cin>>n>>v;
	cout<<solve(n, v)<<'\n';
	return 0;
}
