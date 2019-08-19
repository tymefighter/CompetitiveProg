#include<iostream>
#include<set>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	set<int> s;

	cin>>n;

	while(n--)
	{
		cin>>x;
		s.insert(x);
	}

	if(s.size() == 1)
		cout<<0<<'\n';
	else
	{
		if(*s.begin() == *s.rbegin())
			cout<<0<<'\n';
		else
		{
			s.erase(*s.rbegin());
			cout<<*(s.rbegin())<<'\n';
		}
	}

	return 0;
}
