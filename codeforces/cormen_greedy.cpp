#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> a;
vector<int> x;

int solve(int n, int k)
{
	if(n == 1)
	{
		return 0;
	}
	
	int val = 0;

	for(int i = 1;i < n;i++)
	{
		if(x[i] + x[i-1] < k)
		{
			x[i] = max(x[i], k-x[i-1]);
			val += x[i] - a[i];
		}
	}
	
	return val;
}

int main()
{
	int n, k;
	cin>>n>>k;

	a.resize(n);
	for(int i = 0;i < n;i++)
		cin>>a[i];
	x = a;

	cout<<solve(n, k)<<'\n';

	for(int y : x)
		cout<<y<<" ";
	cout<<'\n';
	return 0;
}
