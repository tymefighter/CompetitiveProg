#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

class Graph
{
	public:

	vector<vector<pair<int, int> > > adjList;

	Graph(int n)
	{
		adjList.resize(n);
	}

	void addEdge(int start, int end, int w)
	{
		adjList[start].push_back(make_pair(end, w));
	}

	int Dijkstra_mod(vector<int> &dist, int s, int e)
	{
		int i, u;
		for(i = 0;i < dist.size(); i++)
			dist[i] = -1;

		dist[s] = 0;
		priority_queue<pair<int, int> >pq;
		pq.push(make_pair(0, s));

		while(pq.empty() == false)
		{
			u = (pq.top()).second;
			pq.pop();
			

			for(auto v : adjList[u])
			{
				if(dist[v.first] == -1 || dist[v.first] > dist[u] + v.second)
				{
					dist[v.first] = dist[u] + v.second;
					pq.push(make_pair(dist[v.first], v.first));
				}
			}
		}

		return dist[e];
	}
};

int main()
{
	int i, n, e, t, m, val, w, start, end, count = 0;
	cin>>n>>e>>t>>m;
	Graph g(n);
	vector<int> dist(n);

	for(i = 0; i < m;i++)
	{
		cin>>start>>end>>w;
		start--, end--;
		g.addEdge(start, end, w);
	}

	e--;
	for(i = 0;i < n;i++)
	{
		if(i == e)
			val = 0;
		else
			val = g.Dijkstra_mod(dist, i, e);


		if(val <= t && val != -1)
			count++;

	}
	cout<<count<<'\n';
	return 0;
}
