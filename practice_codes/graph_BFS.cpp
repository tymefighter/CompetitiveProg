#include<iostream>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

class Graph
{
	private:

	vector<vector<int> > adjList;
	vector<int> visited;
	int n;

	public:

	Graph(int num_nodes)
	{
		n = num_nodes;
		adjList.resize(num_nodes);
	}

	void addEdge(int start, int end)
	{
		adjList[start].push_back(end);

		return;
	}

	vector<int> BFS(int x)
	{
		queue<int> q;
		vector<int> dist;
		int a, i;

		dist.assign(n, -1);

		dist[x] = 0;
		q.push(x);

		while(!q.empty())
		{
			a = q.front();
			q.pop();

			for(i = 0;i < adjList[a].size();i++)
			{
				if(dist[adjList[a][i]] == -1)
				{
					dist[adjList[a][i]] = dist[a] + 1;
					q.push(adjList[a][i]);
				}
			}
		}

		return dist;
	}

	void print_graph()
	{
		int i, j;
		for(i = 0;i < adjList.size();i++)
		{
			cout<<i<<": ";
			for(j = 0;j < adjList[i].size();j++)
			{
				cout<<adjList[i][j]<<" ";
			}
			cout<<'\n';
		}
		return;
	}
};


int main()
{
	int n, edg, start, end, x;

	cin>>n>>edg;
	Graph g(n);
	
	while(edg--)
	{
		cin>>start>>end;
		g.addEdge(start, end);
	}

	cin>>x;
	//g.print_graph();
	vector<int> dist = g.BFS(x);

	for(int i = 0;i < dist.size();i++)
		cout<<dist[i]<<" ";
	cout<<'\n';


	return 0;
}

