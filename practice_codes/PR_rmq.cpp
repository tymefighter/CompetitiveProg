#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

class SegmentTree
{
	private:

	vector<int> st, a;
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
			st[p] = L;
			return;
		}

		build(left(p), L, (L + R)/2);
		build(right(p), (L + R)/2 + 1, R);

		int p1 = st[left(p)], p2 = st[right(p)];

		st[p] = (a[p1] < a[p2]) ? p1 : p2;
		return;
	}

	int rmq(int p, int i, int j, int L, int R)
	{
		if(i > R || j < L)
			return -1;

		if(L >= i && R <= j)
			return st[p];

		int p1 = rmq(left(p), i, j, L, (L + R)/2);
		int p2 = rmq(right(p), i, j, (L + R)/2 + 1, R);

		if(p1 == -1)
			return p2;
		
		if(p2 == -1)
			return p1;

		return (a[p1] < a[p2]) ? p1 : p2;
	}
	
	void update(int idx, int p, int L, int R)
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
		
		int p1 = st[left(p)], p2 = st[right(p)];
		st[p] = (a[p1] < a[p2]) ? p1 : p2;

		return;
	}
	

	public:

	SegmentTree(const vector<int> &vec)
	{
		a = vec;
		n = (int)a.size();
		st.assign(4 * n, 0);

		build(1, 0, n-1);
	}

	int rmq(int i, int j)
	{
		return rmq(1, i, j, 0, n-1);
	}

	void update(int idx, int val)
	{
		a[idx] = val;
		update(idx, 1, 0, n-1);
		return;
	}
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
	while(q--)
	{
		cin>>ch;
		if(ch == 0)
		{
			cin>>i>>j;
			idx = st.rmq(i, j);
			printf("%d %d\n", idx, a[idx]);
		}
		else if(ch == 1)
		{
			cin>>idx>>val;
			st.update(idx, val);
			a[idx] = val;
		}
	}

	return 0;
}
