#include<iostream>
#include<cmath>

using namespace std;

long long int gcd(long long int x, long long int y)
{
	if(y == 0)
		return x;
		
	return gcd(y, x % y);
}

long long int lcm(long long int x, long long int y)
{
	long long int ans = x * (y / gcd(x, y));
	
	return (ans < 0 ? -1 : ans);
}

int n;
long long int lower, upper, l;

void read_solve()
{
	long long int x;
	bool isPossible = true;
	cin>>n;
	
	cin>>l;
	for(int i = 1;i < n;i++)
	{
		cin>>x;
		l = lcm(l, x);
		if (l < 0)
			isPossible = false;
	}
	cin>>lower>>upper;
	
	long long int d = (upper / l) - ((lower - 1) / l);
	
	if(isPossible)								// Remove those which are divisible by l
		cout<<(upper - lower + 1) - d<<"\n";
	else										// None are divisible since l exceeds (10^18)
		cout<<(upper - lower + 1)<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
		read_solve();
	return 0;
}

