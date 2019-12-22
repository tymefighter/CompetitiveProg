#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 2005;

int n, m, k;
vector<vector<int> > a;
bool hasAirport[N];

void reset()
{
	a.clear();
	a.resize(n);
	
	for(int i = 0;i < n;i++)
		hasAirport[i] = false;
}

void read()
{
	int u, v;
	for(int i = 0;i < k;i++)
	{
		cin>>u;
		hasAirport[u - 1] = true;
	}
	
	for(int i = 0;i < m;i++)
	{
		cin>>u>>v;
		u --, v --;
		a[u].push_back(v);
		a[v].push_back(u);
	}	
}

int dist[N], s, t;
deque<int> dq;

void resetD()
{
	for(int i = 0;i < n;i++)
		dist[i] = -1;
	while(!dq.empty())
		dq.pop_front();
}

void Dijkstra()
{
	if(s == t)
	{
		cout<<"0\n";
		return;
	}

	if(!hasAirport[s])
		dist[s] = 1;
	else
		dist[s] = 0;
	dq.push_back(s);
	
	while(!dq.empty())
	{
		int u = dq.front();
		dq.pop_front();
		
		if(u == t)
			break;
		
		for(int v : a[u])
		{
			if(hasAirport[v])
			{
				if(dist[v] == -1
					|| dist[u] < dist[v])
				{
					dist[v] = dist[u];
					dq.push_front(v);
				}
			}
			else if(dist[v] == -1)
			{
				dist[v] = dist[u] + 1;
				dq.push_back(v);
			}
		}
	}
	
	cout<<dist[t]<<"\n";
}

void solve()
{
	int q;
	cin>>q;
	while(q --)
	{
		cin>>s>>t;
		s --, t --;
		resetD();
		Dijkstra();
	}
	cout<<"\n";
}

int main()
{
	int t;
	cin>>t;
	for(int i = 1;i <= t;i++)
	{
		cin>>n>>m>>k;
		reset();
		read();
		printf("Case %d:\n", i);
		solve();
	}
	return 0;
}
