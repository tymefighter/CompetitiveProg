#include<iostream>
#include<cstdio>

using namespace std;
string s;
int n;

void solve()
{
	for(int i = 0;i < s.size();i++)
	{
		s[i] = (s[i] == 'E' ? 'S' : 'E');
	}

	return;
}

int main()
{
	int t, count = 1;

	cin>>t;

	while(t--)
	{
		cin>>n;
		cin>>s;
		solve();

		printf("Case #%d: ", count);
		cout<<s<<'\n';
		count++;
	}

	return 0;
}
