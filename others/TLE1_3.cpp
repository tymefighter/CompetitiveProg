#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<utility>
#include<set>

using namespace std;


class UnionFind
{
	private:
		vector<int> parent, rank, num_ele;

	public:
		
		int num_clusters;
		UnionFind(int n)
		{
			parent.resize(n);
			rank.assign(n, 1);
			num_ele.assign(n, 1);

			num_clusters = n;

			for(int i = 0;i < n;i++)
				parent[i] = i;
		}

		int findSet(int i)
		{
			int j = i, temp;
			while(i != parent[i])
				i = parent[i];

			while(j != parent[j])
			{
				temp = parent[j];
				parent[j] = i;
				j = temp;
			}
	
			return i;
		}

		int isSameSet(int i, int j)
		{
			return findSet(i) == findSet(j);
		}

		void unionSet(int i, int j)
		{
			int a, b;
			if(isSameSet(i, j) == 1)
			{
				//printf("Already in the same set\n");
				return;
			}

			a = findSet(i);
			b = findSet(j);

			num_clusters--;

			if(rank[a] > rank[b])
			{
				parent[b] = a;
				num_ele[a] += num_ele[b];
			}
			else if(rank[a] < rank[b])
			{
				parent[a] = b;
				num_ele[b] += num_ele[a];
			}
			else
			{
				parent[a] = b;
				num_ele[b] += num_ele[a];
				rank[b]++;
			}
			return;
		}

		int numberElements(int i)
		{
			int x = findSet(i);

			return num_ele[x];
		}

		void reinitUF(int n)
		{
			parent.resize(n);
			rank.assign(n, 1);
			num_ele.assign(n, 1);

			for(int i = 0;i < n;i++)
				parent[i] = i;
			return;
		}
};

int main()
{
	int n, m, q, i;
	int start, end, no;
	int idx;
	vector<pair<int, int> >bridges;
	set<int> s;

	stack<int> br, ans;

	cin>>n>>m;

	UnionFind ufds(n);

	for(i = 0;i < m;i++)
	{
		cin>>start>>end;
		bridges.push_back(make_pair(start-1, end-1));
	}

	cin>>q;

	for(i = 0;i < q;i++)
	{
		cin>>no;
		s.insert(no-1);
		br.push(no-1);
	}

	for(i = 0;i < m;i++)
	{
		if(s.count(i) == 0)
		{
			ufds.unionSet(bridges[i].first, bridges[i].second);
			//cout<<ufds.num_clusters<<" "<<bridges[i].first<<" "<<bridges[i].second<<'\n';
		}
	}

	while(br.empty() == 0)
	{
		idx = br.top();
		br.pop();

		ans.push(ufds.num_clusters);
		ufds.unionSet(bridges[idx].first, bridges[idx].second);

		//cout<<ufds.num_clusters<<" "<<bridges[idx].first<<" "<<bridges[idx].second<<'\n';


	}

	while(ans.empty() == 0)
	{
		cout<<ans.top()<<'\n';
		ans.pop();
	}
	return 0;
}
