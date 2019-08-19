#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

int n, s, q, time_taken;
stack<int> carrier;
vector<queue<int> > st_b;

void resetAll()
{
	while(carrier.empty() == false)
		carrier.pop();
	st_b.clear();
	time_taken = 0;
}

void read()
{
	int i, j, num, st;
	cin>>n>>s>>q;

	st_b.resize(n);

	for(i = 0;i < n;i++)
	{
		cin>>num;
		for(j = 0;j < num;j++)
		{
			cin>>st;

			st_b[i].push(st-1);
		}
	}
}

void solve()
{
	bool flag = true, start = true;
	int i, cargo, prev = 0;


	while(flag)
	{
		flag = false;
		for(i = 0;i < n;i++)
		{
			while((carrier.empty() == false) && (carrier.top() == i || st_b[i].size() < q))
			{
				cargo = carrier.top();

				if(cargo != i)
					st_b[i].push(cargo);

				carrier.pop();
				time_taken ++;
			}

			while((st_b[i].empty() == false) && (carrier.size() < s))
			{
				carrier.push(st_b[i].front());
				st_b[i].pop();
				time_taken ++;
			}

			if(st_b[i].size() > 0 || carrier.empty() == false)
			{
				flag = true;

				if(prev < i || start == true)
				{
					time_taken += 2 * (i - prev);
				}
				else
				{
					time_taken += 2 * ((n - prev) + i);
				}

				prev = i;
			}

			start = false;
		}

	}

}

int main()
{
	int t;
	
	cin>>t;
	while(t--)
	{
		resetAll();
		read();
		solve();
		cout<<time_taken+2<<'\n';
	}

	return 0;
}
