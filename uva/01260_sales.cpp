#include<iostream>
#include<set>
#include<map>
#include<vector>

using namespace std;

int main()
{
	map<int, int> m;
	set<int> s;
	int t, n, i, sum, x;
	vector<int> b;

	cin>>t;
	while(t--)
	{
		cin>>n;
		s.clear();
		m.clear();

		b.clear();
		b.resize(n);
		sum = 0;

		for(i = 0;i < n;i++)
		{
			cin>>x;
			b[i] = 0;
			
			for(auto it = s.begin(); it != s.end(); it++)
			{
				if(*it > x)
					break;

				b[i] += m[*it];
			}

			s.insert(x);
			
			if(m.count(x) == 0)
				m[x] = 1;
			else
				m[x] += 1;

			sum += b[i];
		}
		cout<<sum<<'\n';
	}
	return 0;
}
