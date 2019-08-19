#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<utility>


using namespace std;

int main()
{
	int t, n, k;

	cin>>t;
	while(t--)
	{
		cin>>n>>k;

		k = k^(k>>1);

		cout<<k<<'\n';	
	}

	return 0;
}
