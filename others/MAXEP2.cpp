#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n, c, speed = 300, isBroken = 0, i = 0;
	
	cin>>n>>c;



	if(n <= 1000)
	{
		while(isBroken == 0)
		{
			i++;
			cout<<1<<" "<<i<<endl;
			cin>>isBroken;
		}

	}
	else
	{
		while(isBroken == 0)
		{
			i += speed;
			cout<<1<<" "<<i<<endl;
			cin>>isBroken;
		}
		cout<<2<<endl;
		i -= speed;
		
		isBroken = 0;

		while(isBroken == 0)
		{
			i++;
			cout<<1<<" "<<i<<endl;
			cin>>isBroken;
		}
	}

	cout<<3<<" "<<i<<endl;
	return 0;
}

