#include<iostream>
#include<vector>

using namespace std;

vector<vector<int > > adj;
vector<long int> a;
vector<bool> visited;
int N, X;

/*void print_adj()
{
	for(auto row : adj)
	{
		cout<<row[0]<<": ";
		for(auto x : row)
		{
			cout<<x<<" ";
		}
		cout<<'\n';
	}
	return;
}

void print_vec(const vector<long int> &a)
{
	for(long int x : a)
		cout<<x<<" ";
	cout<<'\n';
	return;
}
*/
long int min(long int a, long int b)
{
	if(a < b)
		return a;
	else
		return b;
}

void re_init()
{
	for(int i = 0;i < visited.size();i++)
		visited[i] = false;
	return;
}

void read()
{
	int i, u, v;

	cin>>N>>X;

	a.clear();
	a.assign(N, 0);
	adj.clear();
	adj.resize(N);
	visited.clear();
	visited.assign(N, false);

	for(i = 0;i < N;i++)
		cin>>a[i];
	
	for(i = 0;i < N-1;i++)
	{
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	return;
}


long int dfs(int u)
{
	visited[u] = true;
	long int sum = a[u];

	for(int v : adj[u])
	{
		if(visited[v] == false)
			sum += 1ll*dfs(v);
	}
	
	a[u] = sum + 1ll*X;

	return sum;
}

long int solve(int u)
{
	visited[u] = true;
	long int min_val = min(0, a[u]), val = 0;

	for(int v : adj[u])
	{
		if(visited[v] == false)
		{
			val += solve(v);
		}
	}
	
	min_val = min(min_val, val);
	//cout<<min_val<<'\n';//////

	return min_val;
}

int main()
{
	int t;
	long int sum;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;

	while(t--)
	{
		sum = 0;
		read();
		sum = dfs(0);
		//cout<<sum<<"--\n";
		re_init();
		sum -= solve(0);
		cout<<sum<<'\n';//
		//print_vec(a);//////
	}

	return 0;
}
