#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<utility>

using namespace std;

bool check_edge(vector<pair<int, int> > &a, int u)
{
	for(auto x : a)
	{
		if(x.first == u)
			return true;
	}

	return false;
}

int find_wt(vector<pair<int, int> > &a, int u)
{
	for(auto x : a)
	{
		if(x.first == u)
		{
			//printf("%d %d\n", x.first, x.second);
			return x.second;
		}
	}

	return -100000;
}

int main()
{
	int i, n, cost1, cost2, count, x, w, start, end;
	vector<vector<int> >a;
	vector<vector<pair<int, int> > > adjList;
	vector<bool> visited;
	map<int, int> m;

	cin>>n;
	//cout<<n<<'\n';/////
	adjList.resize(n);
	a.resize(n);
	visited.assign(n, false);

	for(i = 0;i < n;i++)
	{
		cin>>start>>end>>w;
		start--;
		end--;
		
		//printf("%d %d %d\n", n, start, end);
		a[start].push_back(end);
		a[end].push_back(start);
		adjList[start].push_back(make_pair(end, w));
	}

	x = count = 0;
	while(visited[x] == false)
	{
		visited[x] = true;
		m[count] = x;

		//printf("%d %d\n", count, x);

		count++;

		if(visited[a[x][0]] == false)
			x = a[x][0];
		else
			x = a[x][1];
	}
	
	//cout<<count<<'\n';
	cost1 = 0;
	for(i = 0;i < count-1;i++)
	{
		//printf("%d %d\n", m[i]+1, m[i+1]+1);
		if(check_edge(adjList[m[i]], m[i+1]) == false)
			cost1 += find_wt(adjList[m[i+1]], m[i]);
	}

	if(check_edge(adjList[m[count-1]], m[0]) == false)
			cost1 += find_wt(adjList[m[0]], m[count-1]);

	
	cost2 = 0;
	for(i = count - 1;i >= 1;i--)
	{
		if(check_edge(adjList[m[i]], m[i-1]) == false)
			cost2 += find_wt(adjList[m[i-1]], m[i]);
	}

	if(check_edge(adjList[m[0]], m[count-1]) == false)
			cost2 += find_wt(adjList[m[count-1]], m[0]);


	//printf("%d %d\n",cost1, cost2);
	cout<<min(cost1, cost2)<<'\n';
	return 0;
}
