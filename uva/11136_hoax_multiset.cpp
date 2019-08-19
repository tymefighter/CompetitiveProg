#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

int main()
{
	multiset<long int> s;
	long int n, i, c, a, b, val, k, j;

	while(cin>>n)
	{
		if(n == 0)
			break;
		
		s.clear();
		val = 0;
	
		for(i = 0;i < n;i++)
		{
			cin>>k;

			for(j = 0;j < k;j++)
			{
				cin>>c;
				s.insert(c);
			}

			a = *s.begin();
			b = *(s.rbegin());
			s.erase(s.begin());
			auto it = s.end();
			it--;
			s.erase(it);
			val += b - a;
		}

		cout<<val<<'\n';

	}
	return 0;
}
