#include<iostream>
#include<cmath>

using namespace std;

long long int n;
int f[60];

void generate()
{
	f[0] = 0, f[1] = 1;
	
	for(int i = 2;i < 60;i++)
		f[i] = (f[i - 1] + f[i - 2]) % 10;
}

void solve()
{
	long long int idx = pow(2, floor(log2(n))) - 1;
	cout<<f[idx % 60]<<"\n";
}

int main()
{
	int t;
	
	generate();
	cin>>t;
	while(t--)
	{
		cin>>n;
		solve();
	}
	return 0;
}
