#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

int check(int x, const vector<int> &a, const vector<int> &b)
{
	for(int i = 0;i <= 5;i++)
	{
		if(x != a[0] && x != a[1] && x != a[2] && x != b[0] && x != b[1])
			return x;
		x += 1;
	}

	return x;
}

int solve(const vector<int> &a, const vector<int> &b)
{
	//printf("%d %d %d %d %d\n",a[0], a[1], a[2], b[0], b[1]);

	if(a[0] > b[0])
	{
		if(a[1] > b[1])
			return -1;
		else
			return check(a[1] + 1, a, b);
	}
	else	//a[0] < b[0]
	{
		if(a[0] < b[1])
			return check(1, a, b);
		else	//a[0] > b[1]
		{
			if(b[1] > a[1])
				return check(a[1] + 1, a, b);
			else
				return check(a[0] + 1, a, b);	
		}
	}
}

int main()
{
	vector<int> a(3), b(2);
	int ans;

	//cout<<'a';

	while(cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1])
	{
		//printf("%d %d %d %d %d\n",a[0], a[1], a[2], b[0], b[1]);

		if(a[0] == 0 && a[1] == 0 && a[2] == 0 && b[0] == 0 && b[1] == 0)
			break;

		
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());

		ans = solve(a, b);
		if(ans > 52)
			cout<<-1<<'\n';
		else
			cout<<ans<<'\n';
	}
}
