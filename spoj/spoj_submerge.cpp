#include<iostream>
#include<cstdio>
#include<vector>
#include<set>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> tin;
vector<int> fup;
set<int> s;
int timer;


void explore(int x, int parent_x)
{
	visited[x] = true;
	fup[x] = tin[x] = timer++;
	int num_child = 0;

	for(int y : adj[x])
	{
		if(y == parent_x)
			continue;
		else if(visited[y])
		{
			fup[x] = min(fup[x], tin[y]);
		}
		else
		{
			num_child++;
			explore(y, x);
			fup[x] = min(fup[x], fup[y]);
			if(parent_x != -1 && tin[x] <= fup[y])
				s.insert(x);
		}
			
	}

	if(parent_x == -1)
	{
		if(num_child > 1)
			s.insert(x);
	}

	return;
}

void dfs()
{
	int i;
	for(i = 0;i < adj.size();i++)
	{
		if(visited[i] == false)
			explore(i, -1);
	}
	return;
}

int main()
{
	int n, m, i, a, b;

	while(cin>>n>>m)
	{
		if(n == 0 && m == 0)
			break;

		adj.clear();
		visited.clear();
		tin.clear();
		fup.clear();

		adj.resize(n);
		visited.assign(n, false);
		tin.resize(n);
		fup.resize(n);
		timer = 0;
		s.clear();

		for(i = 0;i < m;i++)
		{
			cin>>a>>b;
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}

		dfs();
		cout<<s.size()<<'\n';
	}
	
	return 0;
}
