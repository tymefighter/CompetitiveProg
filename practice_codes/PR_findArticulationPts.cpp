#include<iostream>
#include<cstdio>
#include<vector>
#include<set>

using namespace std;

vector<vector<int> >adj;
vector<bool> visited;
vector<int> tin, fup;
set<int> art;
int timer = 0;

void explore(int x, int parent_x)
{
	visited[x] = true;
	fup[x] = tin[x] = timer++;
	int num_children = 0;

	for(int y : adj[x])
	{
		if(y == parent_x)
			continue;
		else if(visited[y])
			fup[x] = min(fup[x], tin[y]);
		else
		{
			explore(y, x);
			fup[x] = min(fup[x], fup[y]);
			num_children++;
			
			if(parent_x != -1 && fup[y] >= tin[x])
				art.insert(x);
		}
	}

	if(parent_x == -1 && num_children > 1)
		art.insert(x);
}

void dfs()
{
	for(int i = 0;i < adj.size();i++)
	{
		if(!visited[i])
			explore(i, -1);
	}

	return;
}

int main()
{
	int n, m, a, b;

	cin>>n>>m;
	adj.resize(n);
	tin.resize(n);
	fup.resize(n);
	visited.assign(n, false);

	while(m--)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs();

	for(auto it = art.begin(); it != art.end(); it++)
		cout<<*it<<'\n';
			

	return 0;
}
