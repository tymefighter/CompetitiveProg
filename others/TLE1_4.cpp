#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>

using namespace std;

class segmentTree
{
	private:
		vector<int> seg;
		int size;
	public:
	
		void reconstruct(const int &n)
		{
			size = n+1;

			seg.resize(4*size);

			constructTree(n, 0, n, 0);
		}

		void constructTree(const int &n, int low, int high, int pos)
		{
			if(low == high)
			{
				if(low == 1)
					seg[pos] = n;
				else
					seg[pos] = 0;
				return;
			}

			int mid = (low + high)/2;



			constructTree(n, low, mid, 2*pos + 1);
			constructTree(n, mid+1, high, 2*pos + 2);
			seg[pos] = seg[2*pos+1]+seg[2*pos+2];

			return;
		}

		int numRange(const int &start,const int &end, int low, int high, int pos)
		{
			if(start > high || end < low)
				return 0;
			else if(start <= low && end >= high)
				return seg[pos];
			else
			{
				int mid = (low + high)/2;
				return numRange(start, end, low, mid, 2*pos + 1) + numRange(start, end, mid+1, high, 2*pos + 2);
			}
			return 1;
		}
		
		void add(const int &p, int low, int high, int pos)
		{

			if(low == high)
			{
				//cout<<low<<" "<<p<<'\n';
				seg[pos] += 1;
				return;
			}

			int val, mid;

			mid = (low + high)/2;
			
			//cout<<low<<" "<<high<<'\n';

			seg[pos] += 1;

			if(p > mid)
			{
				add(p, mid+1, high, 2*pos+2);
			}
			else if(p <= mid)
			{
				add(p, low, mid, 2*pos+1);
			}
			return;	
		}

		void sub(const int &p, int low, int high, int pos)
		{

			if(low == high)
			{
				//cout<<low<<" "<<p<<'\n';
				seg[pos] -= 1;
				return;
			}

			int val, mid;

			mid = (low + high)/2;
			
			//cout<<low<<" "<<high<<'\n';

			seg[pos] -= 1;

			if(p > mid)
			{
				sub(p, mid+1, high, 2*pos+2);
			}
			else if(p <= mid)
			{
				sub(p, low, mid, 2*pos+1);
			}
			return;	
		}


		void printSegArray(void)
		{
			for(int i = 0;i < seg.size();i++)
				cout<<seg[i]<<" ";

			cout<<'\n';
		}
};

class UnionFind
{
	private:
		vector<int> parent, rank, num_ele;

	public:
		
		segmentTree sTree;
		int nn;

		UnionFind(int n)
		{
			sTree.reconstruct(n);
			nn = n;

			parent.resize(n);
			rank.assign(n, 1);
			num_ele.assign(n, 1);



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

			sTree.sub(num_ele[a], 0, nn, 0);
			sTree.sub(num_ele[b], 0, nn, 0);

			if(rank[a] > rank[b])
			{
				parent[b] = a;


				num_ele[a] += num_ele[b];

				sTree.add(num_ele[a], 0, nn, 0);
			}
			else if(rank[a] < rank[b])
			{
				parent[a] = b;
				num_ele[b] += num_ele[a];

				sTree.add(num_ele[b], 0, nn, 0);
			}
			else
			{
				parent[a] = b;
				num_ele[b] += num_ele[a];
				rank[b]++;

				sTree.add(num_ele[b], 0, nn, 0);

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
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n, q, sum = 0, i;
	int start, end;
	string s;
	cin>>n>>q;

	UnionFind ufds(n);

	while(q--)
	{
		cin>>s>>start>>end;

		if(s == "Charlie")
		{

			ufds.unionSet(start, end);
		}
		else if(s == "Bravo")
		{
			cout<<ufds.sTree.numRange(start, end, 0, n, 0)<<'\n';
		}
	}

	return 0;
}
