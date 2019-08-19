#include<iostream>
#include<cstdio>
#include<vector>
#include<map>

using namespace std;

int main()
{
	vector<vector<long int> > adjList;
	map<long int, long int> m, re_map;
	long int i, n, a, b, count = 0, start, end;


	cin>>n;
	adjList.resize(4*n);


	while(n--)
	{
		cin>>a>>b;

		if(m.count(a) == 0)
		{
			m[a] = count;
			re_map[count] = a;
			count++;

			//cout<<a<<" "<<m[a]<<'\n';
		}

		if(m.count(b) == 0)
		{
			m[b] = count;
			re_map[count] = b;
			count++;

			//cout<<b<<" "<<m[b]<<'\n';
		}
		adjList[m[a]].push_back(m[b]);
		adjList[m[b]].push_back(m[a]);
	}

	count = 0;
	for(i = 0;i < adjList.size();i++)
	{
		if(adjList[i].size() == 1 && count == 0)
		{
			start = i;
			count++;
		}
		else if(adjList[i].size() == 1 && count == 1)
		{
			end = i;
			count++;
		}
	}

	a = start, b = -1;

	while(a != end)
	{
		cout<<re_map[a]<<" ";
		if(b == -1)
		{
			b = a;
			a = adjList[a][0];
		}
		else
		{
			if(b == adjList[a][0])
			{
				b = a;
				a = adjList[a][1];
			}
			else
			{
				b = a;
				a = adjList[a][0];
			}
		}

	}

	cout<<re_map[end]<<'\n';
	return 0;
}
