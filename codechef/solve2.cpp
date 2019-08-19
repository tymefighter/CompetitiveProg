#include<iostream>
#include<queue>
#define CON (1ll*1000000007)
using namespace std;

int n, max_n;
int ans[1000005];

int op(int a, int b)
{
	return (1ll*(a % CON) + 1ll*(b % CON) + ((1ll*(a % CON))*(b % CON)) % CON) % CON;
}

void solve(int n)
{
	for(int i = max_n+1;i <= n;i++)
		ans[i] = op(ans[i-1], i);
}

int main()
{
	
	int t;
	cin>>t;


	ans[1] = 1;
	ans[2] = 5;
	max_n = 2;

	while(t--)
	{
		cin>>n;
		if(n > max_n)
			solve(n);
		max_n = max(max_n, n);
		cout<<ans[n]<<'\n';
	}

	return 0;
}
