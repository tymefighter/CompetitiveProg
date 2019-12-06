#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

int n, m;
char a[1000][1000];
int dist[1000][1000];
deque<pair<int, int> > q;


void read()
{
	scanf("%d %d", &n, &m);
	
	int i, j;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < m;j++)
		{
			cin>>a[i][j];
			dist[i][j] = -1;
		}
	}
}

int ar[] = {-1, 1, 0, 0};
int ac[] = {0, 0, -1, 1};

void bfs()
{
	static int cno = 0;
	cno ++;

	dist[0][0] = 0;
	q.push_back({0, 0});
	
	int i, edge_wt, new_dist;
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
				|| v.second < 0 || v.second >= m)
					continue;
			
			edge_wt = (a[u.first][u.second] != a[v.first][v.second]);
			new_dist = dist[u.first][u.second] + edge_wt;
			
			if(dist[v.first][v.second] == -1 || new_dist < dist[v.first][v.second])
			{
				dist[v.first][v.second] = new_dist;

				if(edge_wt == 0)
					q.push_front({v.first, v.second});
				else
					q.push_back({v.first, v.second});
			}
		}
	}
	
	printf("Case %d: %d\n", cno, dist[n - 1][m - 1]);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		read();
		bfs();
	}
	return 0;
}
