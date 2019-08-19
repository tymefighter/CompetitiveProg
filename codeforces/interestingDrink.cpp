#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> x;
vector<int> m;

void read()
{
	int n, q, i;
	cin>>n;
	x.resize(n);

	for(i = 0;i < n;i++)
		cin>>x[i];

	cin>>q;
	m.resize(q);
	
	for(i = 0;i < q;i++)
		cin>>m[i];
	
	return;
}

int search(int a)
{
	int n = x.size();
	int mid, left = 0, right = n-1;

	if(a < x[0])
		return 0;
	if(a > x[n-1])
		return n;

	while(mid != ((left + right) / 2))
	{
		mid = (left + right) / 2;

		if(a >= x[mid])
		{
			if(mid + 1 < n && x[mid+1] > a)
				return mid+1;

			left = mid+1;
		}
		else
		{
			right = mid-1;
		}
	}

	return mid+1;
}

void solve()
{
	sort(x.begin(), x.end());
	for(int a : m)
	{
		cout<<search(a)<<'\n';
	}

	return;
}

int main()
{
	read();
	solve();
	return 0;
}
