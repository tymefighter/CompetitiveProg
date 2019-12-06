#include<iostream>

using namespace std;

const int INF = 100000000;
int n, a[100005];
int countx, countx1, passed, minVal;

void read()
{
	cin>>n;
	
	minVal = INF;
	passed = 0;
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
		passed = max(a[i], passed);
		minVal = min(a[i], minVal);
	}
}

void solve()
{
	if(minVal <= passed - 2)
	{
		cout<<"-1\n";
		return;
	}
	else if(minVal == passed && passed == n - 1)
	{
		cout<<"0\n";
		return;
	}


	countx = countx1 = 0;
	for(int i = 0;i < n;i++)
	{
		if(a[i] == passed)
			countx ++;
		else if(a[i] == passed - 1)
			countx1 ++;
	}
	
	if(countx1 != passed)
		cout<<"-1\n";
	else
		cout<<(n - passed)<<"\n";
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		read();
		solve();
	}
	return 0;
}
