#include<iostream>

using namespace std;

void printPattern(int a[20000], int n)
{
	int b = 1, val = 0, count = 0;
	int i, j, k;


	for(i = 1; i <= (n*(n-1))/2;i++)
	{
		if(count < 2)
			val++;
		else
			val--;
		if((i-n)%(n-1) == 0 && i >= n)
		{
			b++;
			val = b;
			count = 0;
		}

		if(val >= n-1)
		{
			val = n-1;
			count++;
		}
		a[i-1] = val;
	}

	i = n*(n-1)/2 - 1;

	for(j = 0;j < (n*(n-1))/2;j++)
	{
		a[i+j+1] = a[i-j];
	}
	
	int x = 1, s = 1, x_ch;

	k = 0;
	for(i = 0;i < n;i++)
	{
		cout<<x<<" ";
		x_ch = x;

		for(j = 0;j <= n-2;j++)
		{
			x_ch += a[k];
			k++;
			cout<<x_ch<<" ";
		}
	
		cout<<'\n';
		s++;
		x += s;
	}

	return;
}

int main()
{
	int t, n;
	int a[20000];
	
	cin>>t;

	while(t--)
	{
		cin>>n;
		printPattern(a, n);
	}

	return 0;
}
