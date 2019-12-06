#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, r, m;
vector<vector<int> > a;
vector<int> visited;
queue<pair<int, int> > q;

void reset()
{
	visited.clear();
	visited.assign(n, -1);
	a.clear();
	a.resize(n);
}

bool bfs(int i, int u, int strength)
{
	if(visited[u] != -1)
		return false;

	while(!q.empty())
		q.pop();
		
	q.push({u, strength});
	visited[u] = i;

	while(!q.empty())
	{
		auto x = q.front();
		q.pop();

		if(x.second != 0)
		{
			for(int v : a[x.first])
			{
				if(visited[v] != i && visited[v] != -1)
					return false;
				else if(visited[v] == -1)
				{
					visited[v] = i;
					q.push({v, x.second - 1});
				}
			}
		}
	}

	return true;
}

void read_solve()
{
	cin>>n>>r>>m;
	reset();

	int u, v;
	for(int i = 0;i < r;i++)
	{
		cin>>u>>v;
		u--, v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int k, s;
	bool isOptimal = true;
	for(int i = 0;i < m;i++)
	{
		cin>>k>>s;
		k --;
		if(isOptimal)
			isOptimal &= bfs(i, k, s);
	}

	if(isOptimal)
	{
		for(u = 0;u < n;u++)
		{
			if(visited[u] == -1)
			{
				cout<<"No\n";
				return;
			}
		}
		cout<<"Yes\n";
	}
	else
		cout<<"No\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--)
		read_solve();
	return 0;
}
