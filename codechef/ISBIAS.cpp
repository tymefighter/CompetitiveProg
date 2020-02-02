#include<iostream>
#include<cassert>

using namespace std;

const int N = 100005;
int n, q, a[N], dpi[N], dpd[N];

void read()
{
	cin>>n>>q;
	assert(n < N);
	
	dpi[0] = dpd[0] = 1;
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
		
		if(i > 0)
		{
		
			assert(a[i] != a[i - 1]);
			if(a[i] > a[i - 1])
			{
				dpi[i] = dpi[i - 1];
				dpd[i] = dpd[i - 1];

				if(i - 1 > 0 && a[i - 1] > a[])
			}
			else
			{
				dpi[i] = dpi[i - 1];
				dpd[i] = dpd[i - 1];
			}
		}
		
		cout<<dpi[i]<<" "<<dpd[i]<<"\n";
	}
}

void solve()
{
	int l, r;
	while(q --)
	{
		cin>>l>>r;
		l --, r --;
		if(l == 0)
		{
			if(dpi[r] == dpd[r])
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else
		{
			if(a[l] > a[l - 1])
			{
				cout<<dpi[r] - dpi[l - 1] + 1<<" "<<dpd[r] - dpd[l - 1]<<"\n";
				if(dpi[r] - dpi[l - 1] + 1 == dpd[r] - dpd[l - 1])
					cout<<"YES\n";
				else
					cout<<"NO\n";
			}
			else
			{
				if(dpi[r] - dpi[l - 1] == dpd[r] - dpd[l - 1] + 1)
					cout<<"YES\n";
				else
					cout<<"NO\n"; 
			}
		}
	}
}

int main()
{
	read();
	solve();
	return 0;
}
