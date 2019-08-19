#include<iostream>

using namespace std;


int main()
{
	long int t;
	bool flag = false;
	long int pa, pb;
	long int x, a, b, i, n, com;


	cin>>t;
	while(t--)
	{
		pa = 0, pb = 0, com = 0, flag = false;

		cin>>n>>a>>b;

		for(i = 0;i < n;i++)
		{
			cin>>x;

			if(x%a == 0)
				pa++;
			if(x%b == 0)
				pb++;

			if(x%a == 0 && x%b == 0)
				com++;
		}

		//cout<<com<<" "<<pa<<" "<<pb<<'\n';
		if(com == pa && com == pb)
		{
			cout<<"BOB\n";
			continue;
		}

	
		pa -= com;
		pb -= com;
	
		//cout<<pa<<" "<<pb<<" "<<com<<'\n';

		if(com != 0)
		{
			if(pb > pa)
				cout<<"ALICE\n";
			else
				cout<<"BOB\n";
		}
		else
		{
			if(pa > pb)
				cout<<"BOB\n";
			else
				cout<<"ALICE\n";
		}

	}

	return 0;
}
