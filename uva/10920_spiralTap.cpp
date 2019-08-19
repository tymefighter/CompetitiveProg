#include<iostream>
#include<cstdio>

/*
	Not yet Solved !!!
*/

using namespace std;


void solve(long long int n,long long int p,long long int &i,long long int &j)
{
	long long int curr = 1, next = 2;
	long long int flag = 0, speed = 1, cur_speed = 1;
	i = n/2+1;
	j = i;
	while(!(next > p && curr <= p))
	{
		if(flag%2 != 0)
			speed++;
		curr = next;
		next = next + speed;


		if(flag == 0)
		{
			j = j + cur_speed;
		}
		else if(flag == 1)
		{
			i = i - cur_speed;
		}
		else if(flag == 2)
		{
			j = j - cur_speed;
		}
		else if(flag == 3)
		{
			i = i + cur_speed;
		}
		
		cur_speed = speed;
		flag = (flag + 1)%4;
	}


	//cout<<cur_speed<<" "<<speed<<" "<<curr<<" "<<next<<" "<<i<<" "<<j<<" "<<flag<<'\n';
	while(curr != p)
	{
		curr++;
		if(flag == 0)
		{
			j = j + 1;
		}
		else if(flag == 1)
		{
			i = i - 1;
		}
		else if(flag == 2)
		{
			j = j - 1;
		}
		else if(flag == 3)
		{
			i = i + 1;
		}
		//flag = (flag + 1)%4;

	}

	return;
}


int main()
{
	long long int i, j, n, p;
	while(scanf("%lld %lld",&n, &p) == 2)
	{
		if((n|p) == 0)
			break;

		solve(n, p, i, j);
		printf("Line = %lld, column = %lld.\n", j, i);
	}
}
