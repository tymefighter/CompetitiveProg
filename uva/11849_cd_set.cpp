#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

int main()
{
	int i, n, m, x, val;
	set<int> s;

	while(cin>>n>>m)
	{
		if(n == 0 && m == 0)
			break;

		val = 0;
		s.clear();
		for(i = 0;i < n+m;i++)
		{
			cin>>x;
			if(s.find(x) != s.end())
				val++;
			else
				s.insert(x);
		}
		cout<<val<<'\n';
	}
}
