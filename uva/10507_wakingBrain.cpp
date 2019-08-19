#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>

using namespace std;

int main()
{
	set<int> s;
	map<char, int> m;
	int n, q, i, j, count, k;
	char a, b, c;

	int wakeUps = 0, years = 0, nums = 0;

	vector<vector<int> > adj;
	vector<int> aa;
	
	while(cin>>n)
	{

		cin>>q;

		cin>>a>>b>>c;
		//printf("%d %d %c %c %c\n",n, q, a, b, c);

		count = 0;
		adj.clear();
		adj.resize(n);
		s.clear();
		m.clear();

		if(m.count(a) == 0)
		{
			m[a] = count;
			count++;
		}
		if(m.count(b) == 0)
		{
			m[b] = count;
			count++;
		}
		if(m.count(c) == 0)
		{
			m[c] = count;
			count++;
		}
		s.insert(m[a]);
		s.insert(m[b]);
		s.insert(m[c]);



		for(i = 0;i < q;i++)
		{
			cin>>a>>b;


			if(m.count(a) == 0)
			{
				m[a] = count;
				count++;
			}

			if(m.count(b) == 0)
			{
				m[b] = count;
				count++;
			}

			//printf("%c %d %c %d\n",a, m[a], b, m[b]);

			adj[m[a]].push_back(m[b]);
			adj[m[b]].push_back(m[a]);
		}

		wakeUps = 0, years = 0;

		/*for(i = 0;i < adj.size();i++)
		{
			cout<<i<<": ";
			for(j = 0;j < adj[i].size();j++)
			{
				cout<<adj[i][j]<<" ";
			}
			cout<<'\n';
		}*/

		do
		{
			wakeUps = 0;
			//cout<<"yo\n";
			aa.clear();
			for(i = 0;i < adj.size();i++)
			{
				//cout<<i<<"---\n";

				if(s.count(i) > 0)
					continue;
				nums = 0;
				for(j = 0;j < adj[i].size();j++)
				{
					if(s.count(adj[i][j]) > 0)
						nums++;
				}

				if(nums >= 3)
				{
					//cout<<i<<" ";
					wakeUps++;
					//s.insert(i);
					aa.push_back(i);
				}
			}
			//cout<<'\n';

			for(k = 0;k < aa.size();k++)
				s.insert(aa[k]);

			if(wakeUps > 0)
				years++;

		}while(wakeUps != 0);

		if(s.size() == n)
			printf("WAKE UP IN, %d, YEARS\n",years);
		else
			cout<<"THIS BRAIN NEVER WAKES UP\n";
	}
}
