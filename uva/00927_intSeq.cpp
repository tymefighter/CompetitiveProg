#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	long long int t, i, n, d, k, r, ans;
	vector<int> c;

	cin>>t;
	while(t--)
	{
		cin>>i;
		
		c.clear();
		c.resize(i+1);
		for(n = 0;n <= i;n++)
			cin>>c[n];

		cin>>d;
		cin>>k;

		r = (-1 + sqrt(1 + (8*k)/d))/2;
		if(((r*(r+1))/2)*d != k)
			r++;

		//cout<<r<<"--\n";
		
		ans = 0;
		for(n = 0;n <= i;n++)
			ans += c[n]*pow(r, n);
		cout<<ans<<'\n';
	}

	return 0;
}
