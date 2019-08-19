#include<iostream>
#include<vector>

using namespace std;

bool solve(vector<int> a, int len)
{
	int i, j, sum, n = a.size();

	for(i = 0;i < 1 << n;i++)
	{
		sum = 0;
		
		for(j = 0;j < n;j++)
		{
			if(i & (1 << j))
				sum += a[j];
		}

		if(sum == len)
			return true;
	}

	return false;
}

int main()
{
	int t, len, n, i;
	vector<int> a;

	cin>>t;

	while(t--)
	{
		cin>>len;
		cin>>n;

		a.clear();
		a.resize(n);

		for(i = 0;i < n;i++)
			cin>>a[i];

		if(solve(a, len))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}
