#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

/*

Solution: -

This is a load balancing problem

- We first sort the morning times in non - decreasing
order. Then we sort the afternoon times in 
non - increasing order.
- Now, we make the following pairs: -
a[i] and b[i] for all i in [n].
- Then we may compute the cost, and print it.

*/


int main()
{
	int n, d, r, i, sum, cost;
	vector<int> a, b;

	while(cin>>n>>d>>r)
	{
		if((n|d|r) == 0)
			break;

		a.clear();
		b.clear();
		a.resize(n);
		b.resize(n);

		for(i = 0;i < n;i++)
			cin>>a[i];

		for(i = 0;i < n;i++)
			cin>>b[i];
	
		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());

		sum = 0;
		for(i = 0;i < n;i++)
			sum += max(0, a[i] + b[i] - d);
		
		cost = sum * r;
		cout<<cost<<'\n';
	}

	return 0;
}
