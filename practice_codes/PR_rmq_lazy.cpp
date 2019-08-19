#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>

using namespace std;

/*

	Incomplete -------- 
	- - - - - - - - - - 
*/


class SegmentTree
{
	private:

	vector<int> a;
	vector<pair<int, int> > st, st_lazy;
	int n;

	int left(int i)
	{
		return i << 1;
	}

	int right(int i)
	{
		return (i << 1) + 1;
	}

	void build(int p, int L, int R)
	{
		if(L == R)
		{
			st[p] = {L, a[L]};
			return;
		}

		build(left(p), L, (L + R)/2);
		build(right(p), (L + R)/2 + 1, R);

		pair<int, int> p1 = st[left(p)], p2 = st[right(p)];

		st[p] = (p1.second < p2.second) ? p1 : p2;
		return;
	}

	pair<int, int> rmq(int p, int i, int j, int L, int R)
	{
		if(i > R || j < L)
			return {-1, -1};


		if(L >= i && R <= j)
			return st[p];

		pair<int, int> p1 = rmq(left(p), i, j, L, (L + R)/2);
		pair<int, int> p2 = rmq(right(p), i, j, (L + R)/2 + 1, R);

		if(p1.first == -1)
			return p2;
		
		if(p2.first == -1)
			return p1;

		return (p1.second < p2.second) ? p1 : p2;
	}
	
	/*void update(int idx, int p, int L, int R)
	{
		if(L == R)
		{
			return;
		}
		else if(idx <= (L+R)/2)
		{
			update(idx, left(p), L, (L+R)/2);
		}
		else
		{
			update(idx, right(p), (L+R)/2 + 1, R);
		}
		
		pair<int, int> p1 = st[left(p)], p2 = st[right(p)];
		st[p] = (p1.second < p2.second) ? p1 : p2;

		return;
	}*/
	
	void rangeUpdate(int val, int i, int j, int p, int L, int R)
	{
		if(i > R || j < L)
			return;

		if(L >= i && R <= j)
		{
			if(L == R)
			{
				a[L] += (val + st_lazy[p]);
				st[p] += (val + st_lazy[p]);
				st_lazy[p] = 0;
			}
			else
			{
				st[p] += (val + st_lazy[p]);
				st_lazy[left(p)] += (val + st_lazy[p]);
				st_lazy[right(p)] += (val + st_lazy[p]);

				st_lazy[p] = 0;
			}

			return;
		}
		
		if(st_lazy[p] != 0)
		{
			st[p] += (val + st_lazy[p]);
			st_lazy[left(p)] += st_lazy[p];
		}
		rangeUpdate(i, j, left(p), L, (L + R)/2);
		rangeUpdate(i, j, right(p), (L + R)/2 + 1, R);

		return;
	}
	public:

	SegmentTree(const vector<int> &vec)
	{
		a = vec;
		n = (int)a.size();
		st.assign(4 * n, {0, 0});
		st_lazy.assign(4 * n, {0, 0});

		build(1, 0, n-1);
	}

	int rmq(int i, int j)
	{
		return (rmq(1, i, j, 0, n-1)).first;
	}

	/*void update(int idx, int val)
	{
		a[idx] = val;
		update(idx, 1, 0, n-1);
		return;
	}*/
};

int main()
{
	int n, q, idx, val, i, j, ch;

	cin>>n;
	vector<int> a(n);

	for(i = 0;i < n;i++)
		cin>>a[i];
	
	SegmentTree st(a);

	cin>>q;

	return 0;
}
