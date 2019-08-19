#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

void printVec(const vector<int> &a)
{
	for(int x : a)
		cout<<x<<" ";
	cout<<'\n';
}


class Graph
{
	private:

	vector<vector<int> > adjList;

	public:

	Graph(int n)
	{
		adjList.resize(n);
	}

	void refresh(int size)
	{
		adjList.clear();
		adjList.resize(size);
	}

	void addEdge(int start, int end)
	{
		adjList[start].push_back(end);
	}

	bool check_no_edge()
	{
		for(int i = 0;i < adjList.size();i++)
		{
			if(adjList[i].size() == 0)
				return true;
		}
		
		return false;
	}

	void find_odd_indeg(int &s, int &t)
	{
		int count = 0, i;
		s = t = -1;
		
		for(i = 0;i < adjList.size(); i++)
		{
			if(adjList[i].size() % 2 != 0 && count == 0)
			{
				s = i;
				count ++;
			}
			else if(adjList[i].size() % 2 != 0 && count == 1)
			{
				t = i;
				count ++;
			}
		}
	}


	int BFS(int s, int t, vector<int> &dist)
	{
		queue<int> q;
		int u;

		if(adjList[s].size() < 2 || adjList[t].size() < 2)
			return -1;

		for(int x : adjList[s])
		{
			if(x == t)
				return 1;
		}

		dist[s] = 0;
		q.push(s);

		while(!q.empty())
		{
			u = q.front();
			q.pop();

			for(int x : adjList[u])
			{
				if(dist[x] == -1 && adjList[x].size() > 2)
				{
					dist[x] = dist[u] + 1;
					q.push(x);
				}
			}
		}

		return dist[t];
	}
};



int main()
{
	int n, m, i, s, t, a, b, val;
	Graph g(1);
	vector<int> dist;

	while(cin>>n>>m)
	{
		


		if(n == 0 && m == 0)
			break;


		g.refresh(n);
		//dist.clear();
		//dist.resize(n);

		for(i = 0;i < m;i++)
		{
			cin>>a>>b;
			g.addEdge(a-1, b-1);
			g.addEdge(b-1, a-1);
		}

		if(m == 0 || g.check_no_edge() == true)
		{
			cout<<"Poor Koorosh\n";
			continue;
		}


		g.find_odd_indeg(s, t);

		if(s == -1 && t == -1)
			cout<<0<<'\n';
		else if(s == 0 && t == -1)
			cout<<"Poor Koorosh\n";
		else
		{
			dist.clear();
			dist.assign(n, -1);
			val = g.BFS(s, t, dist);
			if(val < 0)
				cout<<"Poor Koorosh\n";
			else
				cout<<val<<'\n';
		}
		
		/*cout<<s<<" "<<t<<'\n';
		if(s >= 0 && t >= 0)
			cout<<g.BFS(s, t, dist)<<'\n';*/
	}

}

