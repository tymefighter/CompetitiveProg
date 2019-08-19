#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<long int> a;

	long int n, sum, t, i;

	cin>>t;
	while(t--)
	{
		cin>>n;
		a.resize(n);

		for(i = 0;i < n;i++)
			cin>>a[i];

		sort(a.begin(), a.end());
		sum = 0;

		for(i = 0;i < n/2;i++)
		{
			sum += abs(a[n-i-1] - a[i]);
		}
		cout<<sum<<'\n';
	}

	return 0;
}
