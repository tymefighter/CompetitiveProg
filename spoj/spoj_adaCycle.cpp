#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

class Graph
{
	private:

	vector<vector<int> > adjList;

	public:

	Graph(int n)
	{
		adjList.resize(n);
	}

	void addEdge(int start, int end)
	{
		adjList[start].push_back(end);
	}

	int BFS(int s, vector<int> &dist)
	{
		queue<int> q;
		int u;

		for(int i = 0;i < dist.size(); i++)
			dist[i] = -1;

		dist[s] = 0;
		q.push(s);

		while(!q.empty())
		{
			u = q.front();
			q.pop();

			for(int x : adjList[u])
			{
				if(x == s)
					return dist[u] + 1;
				
				if(dist[x] == -1)
				{
					dist[x] = dist[u] + 1;
					q.push(x);
				}
			}
		}

		return -1;
	}
};

int main()
{
	int n, i, j, val;

	cin>>n;
	vector<int> dist(n);
	Graph g(n);

	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			cin>>val;
			
			if(val == 1)
				g.addEdge(i, j);
		}
	}

	for(i = 0;i < n;i++)
	{
		val = g.BFS(i, dist);
		
		if(val != -1)
		{
			printf("%d\n",val);
		}
		else
			printf("NO WAY\n");

	}

	return 0;
}
