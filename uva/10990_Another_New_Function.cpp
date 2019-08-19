#include<iostream>

using namespace std;

const int N = 2000001;
int EulerPhi[N], depth[N], SODF[N];

void generate_arrays()
{	
	int i, j;


	for(i = 1;i <= N;i++)
		EulerPhi[i] = i;
	
	for(i = 2;i <= N;i++)
	{
		if(EulerPhi[i] == i) // prime
		{
			for(j = i;j <= N;j += i)
				EulerPhi[j] -= EulerPhi[j] / i;
		}
	}
	
	SODF[1] = depth[1] = 0;
	for(i = 2;i <= N;i++)
	{
		depth[i] = 1 + depth[EulerPhi[i]];	
		SODF[i] = SODF[i - 1] + depth[i];
	}
}

int main()
{
	int t, n, m;
	cin>>t;
	generate_arrays();
	while(t--)
	{
		cin>>n>>m;
		cout<<SODF[m] - (n > 0 ? SODF[n - 1] : 0)<<"\n";
	}
	return 0;
}
