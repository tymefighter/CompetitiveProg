#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<string>

using namespace std;

int t, n;
int a[15];
set<string> s;

void read()
{
	s.clear();
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	
	sort(a, a + n, greater<int>());
}

void print_choice(int choice)
{
	int i, j, count = 0;
	string str;
	for(j = 1, i = 0;j <= choice; j = j << 1, i++)
	{
		if(j & choice)
		{
			if(count)
				str += "+";
			
			str += to_string(a[i]);
			count++;
		}
	}

	if(s.find(str) == s.end())
	{
		cout<<str<<'\n';
		s.insert(str);
	}
}

void solve(int i, int val, int choice)
{
	if(i == n)
	{
		if(val == t)
			print_choice(choice);
		return;
	}

	if(val > t)
		return;

	solve(i+1, val + a[i], choice | (1 << i));
	solve(i+1, val, choice);
}

int main()
{
	
	while(cin>>t>>n)
	{
		if(n == 0)
			break;
		
		read();
		printf("Sums of %d:\n", t);
		solve(0, 0, 0);
		if(s.empty())
			printf("NONE\n");
	}
}
