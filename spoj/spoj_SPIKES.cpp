#include<iostream>
#include<queue>

using namespace std;

int n, m, j;
int gr, gc;	// goal coordinates
int dist[45][45];
char a[45][45];
deque<pair<int, int> > q;

void read()
{
	cin>>n>>m>>j;
	
	int i, k;
	for(i = 0;i < n;i++)
	{
		for(k = 0;k < m;k++)
		{
			cin>>a[i][k];
			dist[i][k] = -1;
			
			if(a[i][k] == '@')
			{
				dist[i][k] = 0;
				q.push_back({i, k});
			}
			else if(a[i][k] == 'x')
			{
				gr = i;
				gc = k;
			}
		}
	}
}

int ar[] = {-1, 1, 0, 0};
int ac[] = {0, 0, -1, 1};

void bfs()
{
	int i, k, edge_wt;
	pair<int, int> u, v;

	while(!q.empty())
	{
		u = q.front();
		q.pop_front();
		
		for(i = 0;i < 4;i++)
		{
			v.first = u.first + ar[i];
			v.second = u.second + ac[i];
			
			if(v.first < 0 || v.first >= n
				|| v.second < 0 || v.second >= m || a[v.first][v.second] == '#')
				continue;
			
			edge_wt = (a[v.first][v.second] == 's');
			
			if(dist[v.first][v.second] == -1
				|| (dist[u.first][u.second] + edge_wt < dist[v.first][v.second]))
			{
				dist[v.first][v.second] = dist[u.first][u.second] + edge_wt;
				
				if(edge_wt == 0)
					q.push_front({v.first, v.second});
				else
					q.push_back({v.first, v.second});
			}
				
		}
	}
	
	if(dist[gr][gc] == -1 || 2 * dist[gr][gc] > j)
		cout<<"IMPOSSIBLE\n";
	else
		cout<<"SUCCESS\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	read();
	bfs();
	return 0;
}
