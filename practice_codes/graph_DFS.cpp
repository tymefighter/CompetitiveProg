#include<iostream>
#include<stack>
#include<vector>

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

	void explore(int x)
	{
		visited[x] = 1;
		cout<<x<<'\n';
		for(int j = 0;j < adjList[x].size();j++)
		{
			if(visited[adjList[x][j]] == 0)
			{
				explore(adjList[x][j]);
			}
		}
		return;
	}

	void DFS()
	{
		visited.assign(n, 0);

		for(int i = 0;i < n;i++)
		{
			if(visited[i] == 0)
			{
				explore(i);
				cout<<"-----\n";
			}
		}
		return;
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
	int n, edg, start, end;

	cin>>n>>edg;
	Graph g(n);
	
	while(edg--)
	{
		cin>>start>>end;
		g.addEdge(start, end);
	}


	//g.print_graph();
	g.DFS();


	return 0;
}

