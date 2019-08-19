#include<iostream>
#include<cstdio>

using namespace std;

int n, a, b;



void solve()
{
	a = b = 0;
	int x, flag = 0;

	while(n != 0)
	{
		x = n & (-n);

		if(flag == 0)
			a |= x;
		else
			b |= x;
		
		n -= x;
		flag = (flag + 1) % 2;
	}
}

int main()
{
	while(cin>>n)
	{
		if(n == 0)
			break;

		solve();
		printf("%d %d\n", a, b);
	}
	return 0;
}
