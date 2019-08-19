#include<iostream>
#include<vector>
#include<utility>
#include<cstdio>

using namespace std;

int main()
{
	int m, n;
	int i, j, x, r;
	vector<vector<pair<int, int> > >a, b;

	while(cin>>m>>n)
	{
		a.clear();
		b.clear();
		a.resize(m);
		b.resize(n);

		for(i = 0;i < m;i++)
		{
			cin>>r;
		
			for(j = 0;j < r;j++)
			{
				cin>>x;
				a[i].push_back(make_pair(0, x));
			}

			for(j = 0;j < r;j++)
			{
				cin>>x;
				a[i][j].first = x;
			}
		}


		for(i = 0;i < a.size();i++)
		{
			for(j = 0;j < a[i].size();j++)
			{
				b[a[i][j].second-1].push_back(make_pair(a[i][j].first, i+1));
			}
		}

		cout<<n<<" "<<m<<'\n';
	
		for(j = 0;j < b.size();j++)
		{

			cout<<b[j].size();

			for(i = 0;i < b[j].size();i++)
			{
				cout<<" ";
				cout<<b[j][i].second;
			}
			cout<<'\n';
			for(i = 0;i < b[j].size();i++)
			{
				if(i != 0)
					cout<<" ";
				cout<<b[j][i].first;
			}

			cout<<'\n';
		}
	}
	return 0;
}
