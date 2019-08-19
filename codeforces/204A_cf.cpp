#include<iostream>
#include<cmath>

using namespace std;

long long int max(long long int a, long long int b)
{
	if(a > b)
		return a;
	else
		return b;
}

long long int min(long long int a, long long int b)
{
	if(a < b)
		return a;
	else
		return b;
}

void get_values(long long int n, long long int &am, long long  int &a1, long long int &m, long long int &part3)
{
	long long int x = n;
	a1 = n%10;
	m = 0;

	while(x != 0)
	{
		m++;
		if(x/10 == 0)
			am = x;

		x = x/10;
	}

	if(min(am, a1) == am)
	{
		x = n/10;
		long long int place = 1;
		part3 = 0;

		while(x/10 != 0)
		{
			part3 += place*(x%10);

			x = x/10;
			place = place*10;
		}

		part3 += 1;
	}
	else
	{
		if(am != 1)
		{
			while(n%10 != am)
			{
				n--;
			}
			if(n < am*pow(10, m-1))
				part3 = 0;
			else
			{
				x = n/10;
				long long int place = 1;
				part3 = 0;

				while(x/10 != 0)
				{
					part3 += place*(x%10);

					x = x/10;
					place = place*10;
				}
				part3 += 1;
			}
		}
		else
			part3 = 0;
	}

	return;
}

long long int solve(long long int n)
{
	if(n == 0)
		return 0;

	long long int part1, part2, part3;


	long long int am, a1, m;


	get_values(n, am, a1, m, part3);

	part1 = (am-1)*max(pow(10, m-2), 1);

	if(m >= 2)
		part2 = 8 + pow(10, m-2);
	else
		part2 = 0;

	long long int ans = part1 + part2 + part3;

	return ans;
}

int main()
{
	long long int x, y;
	cin>>x>>y;
	if(x != y)
		cout<<solve(y)-solve(x-1)<<'\n';
	else
	{
		long long int a1 = x%10, am;

		while(x != 0)
		{
			if(x/10 == 0)
				am = x;

			x = x/10;
		}

		if(am == a1)
			cout<<"1\n";
		else
			cout<<"0\n";

	}

	return 0;
}
