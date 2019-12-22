#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 205;
const int INF = 100000000;

vector<vector<int> > a;
int n0, n, s, t;
int res[N][N], p[N];

int f;
queue<int> q;
bool vis[N];

void reset()
{
	n = 2 * n0 + 2;

	s = 0;
	t = n - 1;

	a.clear();
	a.resize(n);
	
	int i, j;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
			res[i][j] = 0;
	}
}

void read()
{
	int reg_cap;
	for(int i = 1;i <= n0;i++)
	{
		cin>>reg_cap;
		res[i][i + n0] += reg_cap;
	}
	
	int m, u, v, w;
	cin>>m;
	for(int i = 0;i < m;i++)
	{
		cin>>u>>v>>w;
		res[u + n0][v] += w;
	}
	
	int b, d;
	cin>>b>>d;
	
	for(int i = 0;i < b;i++)
	{
		cin>>u;
		res[s][u] = INF;
	}
	
	for(int i = 0;i < d;i++)
	{
		cin>>u;
		res[u + n0][t] = INF;
	}
	
	for(u = 0;u < n;u++)
	{
		for(v = 0;v < n;v++)
		{
			if(res[u][v] > 0)
			{
				a[u].push_back(v);
				a[v].push_back(u);
			}
		}
	}
}

void resetBFS()
{
	for(int i = 0;i < n;i++)
	{
		vis[i] = false;
		p[i] = -1;
	}

	while(!q.empty())
		q.pop();
}

void augment(int v, int minEdge)
{
	if(v == s)
	{
		f = minEdge;
		return;
	}
	
	augment(p[v], min(minEdge, res[p[v]][v]));
	
	res[p[v]][v] -= f;
	res[v][p[v]] += f;
}

void EdmondsKarp()
{
	int mf = 0;
	
	while(true)
	{
		resetBFS();
		vis[s] = true;
		q.push(s);
		f = 0;
		
		while(!q.empty())
		{
			int u = q.front();
			q.pop();

			if(u == t)
			{
				augment(t, INF);
				break;
			}	

			for(int v : a[u])
			{
				if(res[u][v] > 0 && !vis[v])
				{
					
					vis[v] = true;
					p[v] = u;
					q.push(v);
				}
			}
		}
		
		if(f == 0)
			break;
		mf += f;
	}
	cout<<mf<<"\n";
}

int main()
{
	while(cin>>n0)
	{
		reset();
		read();
		EdmondsKarp();
	}
	return 0;
}
