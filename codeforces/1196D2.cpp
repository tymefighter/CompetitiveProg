#include<iostream>
#define MAX 100000000

using namespace std;

char ch[3] = {'R', 'G', 'B'};
char a[200005], off[200005];
int n, k;

void read()
{
	cin>>n>>k;
	
	for(int i = 0;i < n;i++)
		cin>>a[i];
}

void solve()
{
	int i, j, ans = MAX, val;
	for(j = 0;j < 3;j++)
	{
		for(i = 0;i < n;i++)
			off[i] = ch[(j + i) % 3];
		
		val = 0;
		for(i = 0;i < k;i++)
			val += (a[i] != off[i] ? 1 : 0);
		
		ans = min(ans, val);
		for(;i < n;i++)
		{
			val -= (a[i - k] != off[i - k] ? 1 : 0);
			val += (a[i] != off[i] ? 1 : 0);
			
			ans = min(ans, val);
		}
	}
	
	cout<<ans<<"\n";
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		read();
		solve();
	}	
	return 0;
}
