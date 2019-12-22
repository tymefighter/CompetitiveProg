#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 505;
int n, m, s, t;
vector<vector<pair<int, int> > > a, a_rev;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int dist_s[N], dist_t[N], dist[N];

void reset()
{
	for(int i = 0;i < n;i++)
	{
		dist_s[i] = -1;
		dist_t[i] = -1;
		dist[i] = -1;
	}
	
	a.clear();
	a.resize(n);
	a_rev.clear();
	a_rev.resize(n);
}

void read()
{
	cin>>s>>t;
	int u, v, w;
	for(int i = 0;i < m;i++)
	{
		cin>>u>>v>>w;
		
		a[u].push_back({w, v});
		a_rev[v].push_back({w, u});
	}
}

void resetPQ()
{
	while(!pq.empty())
		pq.pop();
}

void Dijkstra_s()
{
	dist_s[s] = 0;
	pq.push({0, s});
	
	while(!pq.empty())
	{
		pair<int, int> u = pq.top();
		pq.pop();
		
		if(dist_s[u.second] < u.first)
			continue;
			
		
		for(pair<int, int> v : a[u.second])
		{
			if(dist_s[v.second] == -1
				|| dist_s[u.second] + v.first < dist_s[v.second])
			{
				dist_s[v.second] = dist_s[u.second] + v.first;
				pq.push({dist_s[v.second], v.second});
			}
		}
	}
}

void Dijkstra_t()
{
	dist_t[t] = 0;
	pq.push({0, t});
	
	while(!pq.empty())
	{
		pair<int, int> u = pq.top();
		pq.pop();
		
		if(dist_t[u.second] < u.first)
			continue;
		
		for(pair<int, int> v : a_rev[u.second])
		{
			if(dist_t[v.second] == -1
				|| dist_t[u.second] + v.first < dist_t[v.second])
			{
				dist_t[v.second] = dist_t[u.second] + v.first;
				pq.push({dist_t[v.second], v.second});
			}
		}
	}
}

void Dijkstra()
{
	dist[s] = 0;
	pq.push({0, s});
	
	while(!pq.empty())
	{
		pair<int, int> u = pq.top();
		pq.pop();
		
		if(u.second == t)
			break;
		
		if(dist[u.second] < u.first)
			continue;
		
		for(pair<int, int> v : a[u.second])
		{
			if(dist_s[u.second] + v.first + dist_t[v.second] != dist_s[t])
			{
				if(dist[v.second] == -1
					|| dist[u.second] + v.first < dist[v.second])
				{
					dist[v.second] = dist[u.second] + v.first;
					pq.push({dist[v.second], v.second});
				}
			}
		}
	}
}

void solve()
{
	resetPQ();
	Dijkstra_s();
	Dijkstra_t();
	Dijkstra();
	cout<<dist[t]<<"\n";
}

int main()
{
	while(cin>>n>>m)
	{
		if(!(n | m))
			break;
		reset();
		read();
		solve();
	}
	return 0;
}
