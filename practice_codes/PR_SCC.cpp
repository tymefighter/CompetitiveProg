#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> topo;
vector<bool> visited;
vector<int> comp;

void explore(const vector<vector<int> > &adj, int x, bool flag, int no)
{
	visited[x] = true;

	if(!flag)
		comp[x] = no;

	for(int y : adj[x])
	{
		if(!visited[y])
			explore(adj, y, flag, no);
	}
	
	if(flag)
		topo.push_back(x);
}

void DFS(const vector<vector<int> > &adj)
{
	int n = adj.size();
	visited.assign(n, false);

	for(int i = 0;i < adj.size();i++)
	{
		if(!visited[i])
			explore(adj, i, true, 0);
	}

	return;
}

void SCC(const vector<vector<int> > &adj_rev)
{
	int n = adj_rev.size();
	visited.assign(n, false);
	reverse(topo.begin(), topo.end());
	int no = 0;

	for(int x : topo)
	{
		if(!visited[x])
		{
			explore(adj_rev, x, false, no);
			no++;
		}

	}
	return;
}

int main()
{
	vector<vector<int> > adj;
	vector<vector<int> > adj_rev;

	int n, m, a, b;

	cin>>n>>m;

	adj.resize(n);
	adj_rev.resize(n);
	comp.resize(n);

	
	while(m--)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj_rev[b].push_back(a);
	}

	DFS(adj);
	SCC(adj_rev);

	for(int x : comp)
		cout<<x<<'\n';

	return 0;
}
