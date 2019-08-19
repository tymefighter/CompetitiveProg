#include<iostream>
#include<string>

using namespace std;

int leastK(int n, int k)
{
	return n%(1<<(k));
}

int checkPowerTwo(int n)
{
	int t, x, t1;

	t = n&(-n);
	x = n^t;
	t1 = x&(-x);
	printf("%d %d %d\n", t, x, t1);

	if(t1 == 0)
		return 1;
	else 
		return 0;
}

int turnOffLast(int n)
{
	return n&(~(n&(-n)));
}

int turnOnLast(int n)
{
	int x = ~n;
	x = turnOffLast(x);

	return ~x;
}

int turnOffLastConsec(int n)
{
	int x, y, z, ans;

	x = ~n;
	y = x&(-x);
	z = y-1;
	cout<<z<<'\n';
	ans = n&(~z);

	return ans;
}

int turnOnLastConsec(int n)
{
	int x = ~n;

	x = turnOffLastConsec(x);

	return ~x;
}

int main()
{
	int n, k;
	string choice;

	scanf("%d",&n);

	while(cin>>choice)
	{
		if(choice == "leastK")
		{
			cin>>k;
			n = leastK(n, k);
			cout<<n<<'\n';
		}
		else if(choice == "check")
		{
			if(checkPowerTwo(n))
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}
		else if(choice == "TOFFL")
		{
			n = turnOffLast(n);
			cout<<n<<'\n';
		}
		else if(choice == "TONL")
		{
			n = turnOnLast(n);
			cout<<n<<'\n';
		}
		else if(choice == "TOFFLC")
		{
			n = turnOffLastConsec(n);
			cout<<n<<'\n';
		}
		else if(choice == "TONLC")
		{
			n = turnOnLastConsec(n);
			cout<<'\n';
		}
		else if(choice == "change")
		{
			cin>>n;
		}
		else if(choice == "exit")
			break;
	}
	return 0;
}
