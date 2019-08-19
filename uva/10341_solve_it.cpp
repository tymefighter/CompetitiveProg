#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int p, q, r, s, t, u;
double ans, eps = 1e-8;

double func(double x)
{
	return p * exp(- x) + q * sin(x) + r * cos(x) + s * tan(x) + t * (x * x) + u;
}

double b_search(double m_inc)
{
	double low = 0, high = 1, mid;
	mid = (low + high) / 2.0;
	
	while(high - low > eps)
	{
		if(func(mid) == 0)
			return mid;

		if(func(mid) > 0)
		{
			if(m_inc)
				high = mid;
			else
				low = mid;
		}

		if(func(mid) < 0)
		{
			if(m_inc)
				low = mid;
			else
				high = mid;
		}

		mid = (low + high) / 2.0;
	}

	return mid;
}

bool solve()
{
	if(func(0) * func(1) > 0)
		return false;
	
	if(func(0) == 0)
	{
		ans = 0;
		return true;
	}
	if(func(1) == 0)
	{
		ans = 1;
		return true;
	}
	
	if(func(0) < 0)
		ans = b_search(true);
	else
		ans = b_search(false);

	return true;
}

int main()
{
	while(cin>>p>>q>>r>>s>>t>>u)
	{
		if(solve())
			printf("%0.4lf\n", ans);
		else
			printf("No solution\n");
	}

	return 0;
}
