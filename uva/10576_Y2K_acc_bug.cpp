#include<iostream>

using namespace std;

int s, d, ans;

int compute_sum(int start, int end, int choice)
{
	int val, j;
	val = 0;
	start = (1 << start);
	end = (1 << end);

	for(j = start;j <= end; j = j << 1)
	{
		if(j & choice)
			val += s;
		else
			val -= d;
	}


	return val;
}

bool check(int i, int choice)
{
	if(compute_sum(i - 4, i, choice) < 0)
		return true;
	else
		return false;
}

void solve(int i, int val, int choice)
{
	if(i == 12)
	{
		if(check(i-1, choice) == false)
			return;

		if(ans == -1 || val > ans)
			ans = val;
		return;
	}

	if(i >= 5)
	{
		if(check(i-1, choice) == false)
			return;
	}

	solve(i + 1, val + s, choice | (1 << i));
	solve(i + 1, val - d, choice);
}


int main()
{
	while(cin>>s>>d)
	{
		ans = -1;
		solve(0, 0, 0);
		if(ans < 0)
			cout<<"Deficit\n";
		else
			cout<<ans<<'\n';

	}

	return 0;
}
