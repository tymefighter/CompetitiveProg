#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 1000005;

int numDiffPF[N], mu[N], M[N];

void generate()
{
	memset(numDiffPF, 0, sizeof(numDiffPF));
	
	int i, j;
	for(i = 2;i <= N;i++)
	{
		if(numDiffPF[i] == 0)
		{
			for(j = i;j <= N;j += i)
			{
				if(numDiffPF[j] == -1)
					continue;
				else if((j * 1ll) % ((i *1ll) * i) == 0)
					numDiffPF[j] = -1;
				else
					numDiffPF[j] ++;
			}
		}
	}
	
	M[1] = mu[1] = 1;
	for(i = 2;i <= N;i++)
	{
		if(numDiffPF[i] == -1)
			mu[i] = 0;
		else if(numDiffPF[i] % 2)
			mu[i] = -1;
		else
			mu[i] = 1;
		
		M[i] = M[i - 1] + mu[i];
	}
}

int main()
{
	generate();
	int n;
	
	while(cin>>n)
	{
		if(!n)	
			break;
		printf("%8d%8d%8d\n", n, mu[n], M[n]);
	}
	return 0;
}
