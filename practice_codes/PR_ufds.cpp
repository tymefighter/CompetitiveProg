#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<vector>

using namespace std;

class UnionFind
{
	private:
		vector<int> parent, rank, num_ele;
		int num_sets;

	public:
		
		UnionFind(int n)
		{
			parent.resize(n);
			rank.assign(n, 0);
			num_ele.assign(n, 1);
			num_sets = n;

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
			
			num_sets--;
			a = findSet(i);
			b = findSet(j);

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

		int sizeOfSet(int i)
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

		int numDisjointSets()
		{
			return num_sets;
		}

		
};


int main()
{
	UnionFind ufds(0);
	map<string, int> m;
	string a, b;
	int t, n, idx = 0;


	cin>>t;
	while(t--)
	{
		cin>>n;
		ufds.reinitUF(n);
		while(n--)
		{
			cin>>a>>b;


			if(m.count(a) == 0)
			{
				m[a] = idx;
				idx++;
			}
			if(m.count(b) == 0)
			{
				m[b] = idx;
				idx++;
			}

			ufds.unionSet(m[a], m[b]);
			

			cout<<ufds.sizeOfSet(m[a])<<'\n';
		}
	}

	return 0;
}
