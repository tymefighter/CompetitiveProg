#include<iostream>
#include<algorithm>

using namespace std;

int n;
int permutn[8];
int a[8][8];

void read()
{
	int i, j;
	cin>>n;

	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			cin>>a[i][j];
		}
	}
}

int fact(int n)
{
	int val = n;
	while(--n)
		val *= n;
	return val;
}

int compute_val()
{
	int val = 0;

	for(int i = 0;i < n;i++)
		val += a[i][permutn[i]];
	
	return val;
}

int solve()
{
	int i, val, min_val = -1;

	for(i = 0;i < n;i++)
		permutn[i] = i;
	
	for(i = 0;i < fact(n);i++)
	{
		val = compute_val();
		if(min_val == -1 || val < min_val)
			min_val = val;

		next_permutation(permutn, permutn+n);
	}

	return min_val;
}

int main()
{
	int t;

	cin>>t;

	while(t--)
	{
		read();
		cout<<solve()<<'\n';
	}

	return 0;
}
