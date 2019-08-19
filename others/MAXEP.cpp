#include<iostream>
#include<cstdio>
#include<cmath>
#include<cassert>

using namespace std;

int main()
{
	int n, c, speed = 600;
	int isBroken = 0, total_amt = 1000;
	
	cin>>n>>c;
	speed = sqrt(n);

	int i = 1;

	if(n <= 1000)
	{
		while(isBroken == 0)
		{
			cout<<1<<" "<<i<<endl;
			cin>>isBroken;
			total_amt--;
			i++;
		}


		assert(isBroken != -1);


		i--;
	}
	else
	{
		while(isBroken == 0)
		{
			cout<<1<<" "<<i<<endl;
			cin>>isBroken;
			i += speed;
			total_amt--;
		}
		cout<<2<<endl;
		i -= 2*speed;

		assert(isBroken != -1);


		if(i <= 0)
			i = 1;
		total_amt -= c;
		
		isBroken = 0;

		while(isBroken == 0)
		{
			cout<<1<<" "<<i<<endl;
			cin>>isBroken;
			i++;
			total_amt--;
		}

		assert(isBroken != -1);

		i--;
	}

	cout<<3<<" "<<i<<endl;


	assert(isBroken != -1);
	//cout<<total_amt<<endl;
	return 0;
}
