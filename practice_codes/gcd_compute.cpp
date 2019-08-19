#include<iostream>
#include<cstdio>

using namespace std;

int gcd(int a, int b)
{
	if(a == 0)
		return b;
	else if(b == 0)
		return a;

	if(b > a)
		return gcd(a, b%a);
	else
		return gcd(a%b, b);
}

int main()
{
	int t, a, b;

	cin>>t;

	while(t--)
	{
		cin>>a>>b;
		cout<<gcd(a, b)<<'\n';
	}

	return 0;
}
