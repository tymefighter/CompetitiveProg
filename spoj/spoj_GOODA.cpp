#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> topo;
vector<bool> visited;
vector<int> comp;
vector<long int> ans;


void print_adj(const vector<vector<int> > &a)
{
	int i = 0;
	for(auto row : a)
	{
		cout<<i<<": ";
		for(auto x : row)
		{
			cout<<x<<" ";
		}
		i++;
		cout<<'\n';
	}

	return;
}

void explore(const vector<vector<int> > &adj, int x, bool flag, int no)
{
	visited[x] = 1;

	if(!flag)
		comp[x] = no;

	for(int y : adj[x])
	{
		if(!visited[y])
			explore(adj, y, flag, no);
	}
	
	if(flag)
		topo.push_back(x);
}

void DFS(const vector<vector<int> > &adj)
{
	int n = adj.size();
	visited.assign(n, false);

	for(int i = 0;i < adj.size();i++)
	{
		if(!visited[i])
			explore(adj, i, true, 0);
	}

	return;
}

int SCC(const vector<vector<int> > &adj_rev)
{
	int n = adj_rev.size();
	visited.assign(n, false);
	reverse(topo.begin(), topo.end());
	int no = 0;

	for(int x : topo)
	{
		if(!visited[x])
		{
			explore(adj_rev, x, false, no);
			no++;
		}

	}
	return no;
}


long int solve(int s, int e, const vector<vector<int> > &con, const vector<long int> &con_wt)
{
	ans.assign(con.size(), -10000000000);
	int i = 0;

	while(s != topo[i])
		i++;
	
	//cout<<i<<'\n';/////////

	ans[s] = con_wt[s];
	long int val = 0;

	for(;i < topo.size();i++)
	{
		for(int x : con[i])
		{
			val = ans[topo[i]] + (1ll)*con_wt[x];
			//cout<<val<<"-----a\n";

			if(val > ans[x])
				ans[x] = val;
		}
	}


	return ans[e];
}


int main()
{
	vector<vector<int> > adj;
	vector<vector<int> > adj_rev;
	vector<int> adj_wt;

	int n, m, s, e, a, b, i;

	cin>>n>>m>>s>>e;
	s--, e--;

	adj.resize(n);
	adj_rev.resize(n);
	adj_wt.resize(n);
	comp.resize(n);

	for(i = 0;i < n;i++)
	{
		cin>>adj_wt[i];
	}
	
	for(i = 0;i < m;i++)
	{
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj_rev[b-1].push_back(a-1);
	}

	DFS(adj);
	int no_comp = SCC(adj_rev);
	//cout<<no_comp<<"---\n";

	vector<vector<int> > con;
	vector<long int> con_wt;

	con.resize(no_comp);
	con_wt.assign(no_comp, 0);

	s = comp[s];
	e = comp[e];

	for(i = 0;i < adj.size();i++)
	{
		con_wt[comp[i]] += (1ll)*adj_wt[i];
		//cout<<con_wt[comp[i]]<<"-----\n";
		for(int j : adj[i])
		{
			if(comp[i] != comp[j])
			{
				con[comp[i]].push_back(comp[j]);
			}
		}
	}

	adj.clear();
	adj_wt.clear();
	adj_rev.clear();

	topo.clear();

	DFS(con);
	reverse(topo.begin(), topo.end());

	//print_adj(con);

	cout<<solve(s, e, con, con_wt)<<'\n';

	return 0;
}

