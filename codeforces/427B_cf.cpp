#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, t, c;
	
	cin>>n>>t>>c;

	int a, i, x, sum;


	x = 0;
	sum = 0;
	for(i = 0;i < n;i++)
	{
		cin>>a;
		if(a <= t)
			x++;
		else
		{
			sum += max(0, x+1-c);
			x = 0;
		}
	}

	if(x != 0)
		sum += max(0, x+1-c);

	cout<<sum<<'\n';
	return 0;
}
