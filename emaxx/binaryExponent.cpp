#include<iostream>
#include<cstdio>

using namespace std;

long long int binaryExpRec(long long int a, int n)
{
	if(n == 0)
		return 1;
	
	long long int val = binaryExpRec(a, n/2);

	if(n%2 == 0)
	{
		return val*val;
	}
	else
	{
		return val*val*a;
	}
}

long long int binaryExp(long long int a, int n)
{
	if(n == 0)
		return 1;
	
	long long int ans = 1;
	
	while(n > 0)
	{
		if(n & 1)
		{
			ans *= a;
		}
		
		a *= a;
		n = n>>1;
	}

	return ans;
}

int main()
{
	int t, n;
	long long int a;
	cin>>t;
	
	while(t--)
	{
		cin>>a>>n;
		cout<<binaryExp(a, n)<<' '<<binaryExpRec(a, n)<<'\n';

	}

	return 0;
}
