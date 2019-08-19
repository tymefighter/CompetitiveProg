#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

string a, b, c;

void solve()
{
	b.clear();
	c.clear();
	int i = 0;

	while(a[i] != '4')
	{
		b.push_back(a[i]);
		i++;
	}
	
	for(;i < a.size();i++)
	{
		if(a[i] == '4')
		{
			b.push_back('3');
			c.push_back('1');
		}
		else
		{
			b.push_back(a[i]);
			c.push_back('0');
		}
	}

	return;

}


int main()
{
	int t, count = 1;

	cin>>t;

	while(t--)
	{
		cin>>a;
		solve();

		printf("Case #%d: ", count);
		cout<<b<<" "<<c<<'\n';
		count++;
	}

	return 0;
}
