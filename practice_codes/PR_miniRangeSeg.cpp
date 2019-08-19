#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

#define LARGE 1e+8

using namespace std;

class segmentTree
{
	private:
		vector<int> seg;
		int n;
	public:
		segmentTree(vector<int> a)
		{
			n = a.size();
			if(n == (n&(-n)))
				seg.resize(2*n - 1);
			else
				seg.resize(2*(pow(2, log(n)) + 1) - 1);

			constructTree(a, 0, n-1, 0);
		}

		void constructTree(vector<int> a, int low, int high, int pos)
		{
			if(low == high)
			{
				seg[pos] = a[low];
				return;
			}

			int mid = (low + high)/2;



			cout<<low<<" "<<mid<<" "<<pos<<'\n';
			constructTree(a, low, mid, 2*pos + 1);
			constructTree(a, mid+1, high, 2*pos + 2);
			seg[pos] = min(seg[2*pos+1], seg[2*pos+2]);

			return;
		}

		int minRange(int start, int end, int low, int high, int pos)
		{	
			int mid;
			if(start >= low && end <= low)
				return seg[pos];
			else if((start < low && end < low) || (start > high && end > high))
				return LARGE;
			else
			{
				mid = (low + high)/2;
				return min(minRange(start, end, low, mid, 2*pos+1), minRange(start, end, mid, high, 2*pos+2));
			}
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
	int n;
	vector<int> a;

	cin>>n;
	a.resize(n);
	for(int i = 0;i < n;i++)
		cin>>a[i];

	segmentTree s(a);

	s.printSegArray();
}
