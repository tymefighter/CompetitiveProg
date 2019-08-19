#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n, t, m;
queue<pair<int, bool> > Q; // false: left, true: right
queue<pair<int, int> > left_q, right_q;
vector<pair<int, int> > ans;


void read()
{
	cin>>n>>t>>m;
	string dir;
	int arr_time;

	for(int i = 0;i < m;i++)
	{
		cin>>arr_time>>dir;
		if(dir == "left")
			Q.push({arr_time, false});
		else
			Q.push({arr_time, true});
	}
}

void solve()
{
	int curr_time = 0, arr_time, no, i;
	bool loc = false;
	int idx = 0;

	while((Q.empty() == false) || (left_q.empty() == false) || (right_q.empty() == false))
	{
		no = 0;
		if((Q.empty() == false) && (left_q.empty() == true) && (right_q.empty() == true))
		{
			curr_time = Q.front().first;


			while((Q.empty() == false) && Q.front().first == curr_time)
			{
				if(loc == Q.front().second && no < n)
				{
					no++;
					ans.push_back({idx, curr_time+t});
				}
				else
				{
					if(Q.front().second == false)
						left_q.push({idx, curr_time});
					else
						right_q.push({idx, curr_time});
				}

				Q.pop();
				idx++;
			}

		}
		else if((loc == false) && (left_q.empty() == false))
		{

			while((left_q.empty() == false) && no < n)
			{
				ans.push_back({left_q.front().first, curr_time+t});
				left_q.pop();
				no++;
			}
		}
		else if((loc == true) && (right_q.empty() == false))
		{

			while((right_q.empty() == false) && no < n)
			{
				ans.push_back({right_q.front().first, curr_time+t});
				right_q.pop();
				no++;
			}
		}
		
		arr_time = curr_time + t;

		while((Q.empty() == false) && (Q.front().first <= arr_time))
		{

			if(Q.front().second == false)
				left_q.push({idx, Q.front().first});
			else
				right_q.push({idx, Q.front().first});

			Q.pop();
			idx++;
		}

		curr_time = arr_time;
		loc = !loc;

	}

}

int main()
{
	int c, ct = 0;
	cin>>c;

	while(c--)
	{
		if(ct != 0)
			cout<<'\n';
		ans.clear();
		read();
		solve();
		sort(ans.begin(), ans.end());
		for(auto x : ans)
			cout<<x.second<<'\n';
		ct++;
	}

	return 0;
}

