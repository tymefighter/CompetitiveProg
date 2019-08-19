#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

void swap(char *a, char *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	return;
}

void rotate(char b[1000][1000], int n, char temp[1000][1000])
{
	int i, j;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			temp[i][j] = b[j][i];
		}
	}

	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			b[i][j] = temp[i][j];
		}
	}


	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n/2;j++)
		{
			swap(&b[i][j], &b[i][n-j-1]);
		}
	}

	
	return;
}

int checkSim(char a[1000][1000], int rs, int cs, char b[1000][1000], int n)
{
	int i, j, flag = 0;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			if(a[rs+i][cs+j] != b[i][j])
			{
				flag = 1;
				break;
			}
		}
	}

	if(flag == 0)
		return 1;
	else
		return 0;
}

int countSim(char a[1000][1000], int N, char b[1000][1000], int n)
{
	int sum = 0;
	int i, j;
	for(i = 0;i < n*floor(N/n);i++)
	{
		for(j = 0;j < n*floor(N/n);j++)
		{
			sum += checkSim(a, i, j, b, n);
		}
	}

	return sum;
}

int main()
{
	char a[1000][1000], b[1000][1000], temp[1000][1000];
	int N, n;
	int i, j;
	
	while(scanf("%d %d",&N, &n) == 2)
	{
		if((N|n) == 0)
			break;

		for(i = 0;i < N;i++)
		{
			for(j = 0;j < N;j++)
			{
				cin>>a[i][j];
			}
		}

		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				cin>>b[i][j];
			}
		}

		cout<<countSim(a, N, b, n)<<" ";
		rotate(b, n, temp);
		cout<<countSim(a, N, b, n)<<" ";
		rotate(b, n, temp);
		cout<<countSim(a, N, b, n)<<" ";
		rotate(b, n, temp);
		cout<<countSim(a, N, b, n)<<"\n";
	}
	return 0;
}
