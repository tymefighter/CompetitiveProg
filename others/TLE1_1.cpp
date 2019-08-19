#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<utility>


using namespace std;

class segmentTree
{
	private:
		vector<int> seg, arr;
		int n;
	public:
		segmentTree(const vector<int> &a)
		{
			n = a.size();
			arr = a;

			seg.resize(4*n);
			constructTree(a, 0, n-1, 0);
		}

		void constructTree(const vector<int> &a, int low, int high, int pos)
		{
			if(low == high)
			{
				seg[pos] = a[low]^1;
				return;
			}

			int mid = (low + high)/2;



			//cout<<low<<" "<<mid<<" "<<pos<<'\n';
			constructTree(a, low, mid, 2*pos + 1);
			constructTree(a, mid+1, high, 2*pos + 2);
			seg[pos] = seg[2*pos+1]+seg[2*pos+2];

			return;
		}

		int numZeros(const int &start,const int &end, int low, int high, int pos)
		{
			if(start > high || end < low)
				return 0;
			else if(start <= low && end >= high)
				return seg[pos];
			else
			{
				int mid = (low + high)/2;
				return numZeros(start, end, low, mid, 2*pos + 1) + numZeros(start, end, mid+1, high, 2*pos + 2);
			}
			return 1;
		}
		
		void toggle(const int &p, int low, int high, int pos)
		{

			if(low == high)
			{
				//cout<<low<<" "<<p<<'\n';
				arr[p] ^= 1;
				seg[pos] ^= 1;
				return;
			}

			int val, mid;

			mid = (low + high)/2;
			
			//cout<<low<<" "<<high<<'\n';

			if(arr[p] == 0)
				seg[pos] -= 1;
			else
				seg[pos] += 1;

			if(p > mid)
			{
				toggle(p, mid+1, high, 2*pos+2);
			}
			else if(p <= mid)
			{
				toggle(p, low, mid, 2*pos+1);
			}
			return;	
		}

		int occ(const int &k, int low, int high, int pos, int curr)
		{
			if(k > seg[0])
				return -1;

			if(low == high)
				return low;
			
			//cout<<low<<" "<<high<<" "<<curr<<" "<<seg[2*pos+1]<<" "<<k<<'\n';
			int mid = (low + high)/2;

			if(k > curr + seg[2*pos + 1])
				return occ(k, mid+1, high, 2*pos+2, curr+seg[2*pos+1]);
			else
				return occ(k, low, mid, 2*pos+1, curr);
		}

		void printSegArray(void)
		{
			for(int i = 0;i < seg.size();i++)
				cout<<seg[i]<<" ";

			cout<<'\n';
		}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);	

	int n, q, i, p, k, start, end, type;
	vector<int> a;
	cin>>n>>q;
	a.resize(n);

	for(i = 0;i < n;i++)
		cin>>a[i];

	segmentTree s(a);
	//s.printSegArray();
	
	while(q--)
	{
		cin>>type;

		if(type == 1)
		{
			cin>>start>>end;
			cout<<s.numZeros(start, end, 0, n-1, 0)<<'\n';
		}
		else if(type == 2)
		{
			cin>>p;
			s.toggle(p, 0, n-1, 0);
			//s.printSegArray();
		}
		else if(type == 3)
		{
			cin>>k;
			cout<<s.occ(k, 0, n-1, 0, 0)<<'\n';
		}
	}
		
}

