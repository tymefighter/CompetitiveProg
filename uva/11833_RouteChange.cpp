#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 255;
int n, m, c, k, end_pt;
vector<vector<pair<int, int> > > a;
int ser_cost[N], dist[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

void reset()
{
	a.clear();
	a.resize(n);
	
	for(int i = 0;i < n;i++)
		dist[i] = ser_cost[i] = -1;
		
	while(!pq.empty())
		pq.pop();
}

void read()
{
	int u, v, w;
	for(int i = 0;i < m;i++)
	{
		cin>>u>>v>>w;
		a[u].push_back({w, v});
		a[v].push_back({w, u});
	}
	
	end_pt = c - 1;
}

const int ERR_NEG_INF = -100000000; 

int traverseServRoad(int u)
{
	if(u == c - 1)
	{
		ser_cost[u] = 0;
		return 0;
	}
	
	for(pair<int, int> v : a[u])
	{
		if(v.second == u + 1)
		{
			ser_cost[u] = v.first + traverseServRoad(v.second);
			return ser_cost[u];
		}
	}
	
	return ERR_NEG_INF;
}

void solve()
{
	(void)traverseServRoad(0);
	dist[k] = 0;
	pq.push({0, k});
	
	while(!pq.empty())
	{
		pair<int, int> u = pq.top();
		pq.pop();
		
		if(u.second == end_pt)
			break;
		
		if(dist[u.second] < u.first)
			continue;
			
			
		if(0 <= u.second && u.second < c)
		{
			if(dist[c - 1] == -1
				|| dist[u.second] + ser_cost[u.second] <= dist[c - 1])
			{
				dist[c - 1] = dist[u.second] + ser_cost[u.second];
				pq.push({dist[c - 1], c - 1});
			}
			continue;
		}
		
		for(pair<int, int> v : a[u.second])
		{
			if(dist[v.second] == -1
				|| dist[u.second] + v.first < dist[v.second])
			{
				dist[v.second] = dist[u.second] + v.first;
				pq.push({dist[v.second], v.second});
			}
		}
	}
	
	cout<<dist[end_pt]<<"\n";
}

int main()
{
	while(cin>>n>>m>>c>>k)
	{
		if(!(n | m | c | k))
			break;
		reset();
		read();
		solve();
	}
	return 0;
}
