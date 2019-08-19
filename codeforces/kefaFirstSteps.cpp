#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n, max_val, curr_val, prev, curr;

	cin>>n>>prev;
	n--;
	max_val = curr_val = 1;

	while(n--)
	{
		cin>>curr;
		
		if(curr >= prev)
		{
			curr_val += 1;
		}
		else
		{
			if(curr_val > max_val)
				max_val = curr_val;
			curr_val = 1;
		}
		prev = curr;
	}

	if(curr_val > max_val)
		max_val = curr_val;
	cout<<max_val<<'\n';
	return 0;
}
