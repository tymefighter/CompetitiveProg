#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class UnionFind
{
	private:

	vector<int> parent, rank;

	public:

	UnionFind(int n)
	{
		int i;
		parent.resize(n);
		rank.resize(n);

		for(i = 0;i < n;i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int findSet(int x)
	{
		int i = x, j, temp;

		while(i != parent[i])
			i = parent[i];

		j = x;
		while(j != parent[j])//Path compression
		{
			temp = parent[j];
			parent[j] = i;
			j = temp;
		}

		return i;
	}

	bool isSameSet(int a, int b)
	{
		return findSet(a) == findSet(b);
	}

	void unionSet(int a, int b)
	{
		if(isSameSet(a, b))
			return;

		int p_a = findSet(a);
		int p_b = findSet(b);

		if(rank[p_a] > rank[p_b])
		{
			parent[p_b] = p_a;
		}
		else if(rank[p_a] < rank[p_b])
		{
			parent[p_a] = p_b;
		}
		else
		{
			parent[p_b]= p_a;
			rank[p_a]++;
		}

		return;
	}

	void reset(int n)
	{
		parent.clear();
		rank.clear();

		parent.resize(n);
		rank.resize(n);

		for(int i = 0;i < n;i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}
};


int main()
{
	int t, n, a, b, s, f, count = 0;
	char c, line[128];
	UnionFind ufds(0);


	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &t);
	fgets(line, sizeof(line), stdin);

	while(t--)
	{

		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &n);

		ufds.reset(n);
		s = 0, f = 0;


		while(fgets(line, sizeof(line), stdin)!= NULL)
		{
			if(strcmp(line, "\n") == 0)
				break;
			sscanf(line, "%c %d %d", &c, &a, &b);

			if(c == 'c')
				ufds.unionSet(a-1, b-1);
			else if(c == 'q')
			{
				if(ufds.isSameSet(a-1, b-1))
					s++;
				else
					f++;
			}

		}
		
		if(count != 0)
			cout<<'\n';
		cout<<s<<','<<f<<"\n";
		count++;
	}

	return 0;
}
