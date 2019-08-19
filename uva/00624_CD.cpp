#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int n, num_tr;
int cap_ans, val_ans, ans;
vector<int> track;

void read()
{
	cin>>num_tr;
	track.resize(num_tr);

	val_ans = cap_ans = ans = 0;

	for(int i = 0;i < num_tr;i++)
		cin>>track[i];
}

void solve(int cap, int i, int val, int choices)
{
	if(i == num_tr)
	{
		if(val > val_ans)
		{
			val_ans = val;
			ans = choices;
		}
		return;
	}

	solve(cap, i+1, val, choices);
	if(cap - track[i] >= 0)
		solve(cap - track[i], i+1, val+track[i], choices | (1 << i));
}

void print_ans()
{
	int i, j, sum_ans = 0;
	for(i = 1, j = 0;i <= ans; i = i << 1, j++)
	{
		//cout<<j<<"--\n";
		if(i & ans)
		{
			cout<<track[j]<<" ";
			sum_ans += track[j];
		}
	}

	printf("sum:%d\n", sum_ans);
}

int main()
{
	while(cin>>n)
	{
		read();
		solve(n, 0, 0, 0);
		print_ans();
	}

	return 0;
}
