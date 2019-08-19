#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<long long int> a;
	int n = 0, x;

	while(cin>>x)
	{
		a.push_back(x);
		n++;

		if(n%2 == 0)
		{
			nth_element(a.begin(), a.begin()+(n/2-1), a.end());
			nth_element(a.begin(), a.begin()+(n/2), a.end());

			cout<<(a[n/2-1]+a[n/2])/2<<'\n';
		}
		else
		{
			nth_element(a.begin(), a.begin()+(n/2), a.end());

			cout<<(a[n/2])<<'\n';
		}
	}

	return 0;
}
