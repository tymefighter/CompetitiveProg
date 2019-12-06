#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<set>

using namespace std;

typedef struct Triplet
{
    int a, b, c;
} Triplet;

typedef struct TripComp
{
	bool operator() (const Triplet &u, const Triplet &v)
	{
		if(u.a != v.a)
			return u.a < v.a;
		else if(u.b != v.b)
			return u.b < v.b;
		else
			return u.c < v.c;
	}
} TripComp;

int n, m, k;
int dist[3005][3005], pre[3005][3005];
vector<vector<int> > a;
set<Triplet, TripComp> s;
queue<pair<int, int> > q;

void reset()
{
	s.clear();
    a.clear();
    a.resize(n);

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            dist[i][j] = -1;
            pre[i][j] = -1;
        }
    }
    
    while(!q.empty())
    	q.pop();
}

void read()
{
    cin>>n>>m>>k;
    reset();

    int u, v;
    Triplet x;

    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        u --, v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i = 0;i < k;i++)
    {
        cin>>x.a>>x.b>>x.c;
        x.a--, x.b--, x.c--;
        s.insert(x);
    }
}

void printPath(int u, int v)
{
	if(u == -1)
	{
		cout<<"1 ";
		return;
	}
	
	printPath(pre[u][v], u);
	cout<<v + 1<<" ";
}

//  BFS on the graph formed by pair of vertices
void bfs()
{
    for(int v : a[0])
    {
        dist[0][v] = 1;
        if(v == n - 1)
		{
			cout<<dist[0][v]<<"\n";
			printPath(0, v);
			cout<<"\n";
			return;
		}
        q.push({0, v});
    }

    int dval;
    pair<int, int> u;
    Triplet check_triple;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        check_triple.a = u.first;
        check_triple.b = u.second;
        dval = dist[u.first][u.second];

        for(int v : a[u.second])
        {
            check_triple.c = v;
            if(dist[u.second][v] == -1 && s.find(check_triple) == s.end())
            {
                dist[u.second][v] = dval + 1;
                pre[u.second][v] = u.first;
                
                if(v == n - 1)
                {
                	cout<<dist[u.second][v]<<"\n";
                	printPath(u.second, v);
                	cout<<"\n";
                	return;
                }
                
                q.push({u.second, v});
            }
        }
    }
    
    cout<<"-1\n";
}

int main()
{
	read();
	bfs();
	return 0;
}
