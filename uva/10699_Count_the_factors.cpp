#include<iostream>
#include<cstring>

using namespace std;

const int N = 1000005;
int numDiffPF[N];

void generate()
{
	memset(numDiffPF, 0, sizeof(numDiffPF));
	
	int i, j;
	for(i = 2;i <= N;i++)
	{
		if(numDiffPF[i] == 0)
		{
			for(j = i;j <= N;j += i)
				numDiffPF[j] ++;
		}
	}
}


int main()
{
	int n;
	generate();
	while(cin>>n)
	{
		if(!n)
			break;
		cout<<n<<" : "<<numDiffPF[n]<<"\n";
	}	
	return 0;
}
