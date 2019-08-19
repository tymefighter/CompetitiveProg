#include<iostream>

using namespace std;


void solve(int n)
{
	int i, x, flag = 0, dig_used, temp;
	for(i = 1234;i <= 98765/n;i++)
	{
		x = i*n;

		dig_used = (i < 10000) ? 1 : 0; //If i is a 4 digit number, set 0 to be used

		temp = i;
		while(temp)
		{
			dig_used |= 1 << (temp%10);
			temp /= 10;
		}

		temp = x;
		while(temp)
		{
			dig_used |= 1 << (temp%10);
			temp /= 10;
		}

		if(dig_used == (1 << 10) - 1)
		{
			flag = 1;
			printf("%0.5d / %0.5d = %d\n",x, i, n);
		}
	}

	if(flag == 0)
		printf("There are no solutions for %d.\n",n);
}


int main()
{
	int n, count = 0;
	while(cin>>n)
	{
		if(n == 0)
			break;


		if(count != 0)
			cout<<'\n';
		solve(n);
		count++;
	}


	return 0;
}
