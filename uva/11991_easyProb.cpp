#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
	map<int, int> m;
	int n, q, c;
	int k, v, i, x;
	vector<vector<int> > a;

	while(cin>>n>>q)
	{
		c = 0;
		m.clear();
		a.clear();
		a.resize(n);

		for(i = 0;i < n;i++)
		{
			cin>>x;
			
			if(m.count(x) == 0)
			{
				m[x] = c;
				c++;
			}
			a[m[x]].push_back(i+1);
		}

		for(i = 0;i < q;i++)
		{
			cin>>k>>v;
			
			if(k > a[m[v]].size())
				cout<<0<<'\n';
			else
				cout<<a[m[v]][k-1]<<"\n";
		}
	}
}
