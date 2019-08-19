#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<set>

using namespace std;

vector<string> a;
vector<bool> flag;
int n;
set<string> s;


int solve(int i, int count)
{
	if(i == a.size())
		return count;

	if(flag[i])
	{
		return solve(i+1, count);
	}

	int k, r, val, max_val = count;

	for(k = 0;k < a[i].size();k++)
	{
		if(s.find(a[i].substr(a[i].size() - k - 1)) != s.end())
				continue;

		for(r = i+1;r < a.size();r++)
		{
			
			if((flag[r] == false) && (a[r].size() >= (k+1)) && (a[i].substr(a[i].size() - k - 1) == a[r].substr(a[r].size() - k - 1)))
			{
				//cout<<a[i].substr(a[i].size() - k - 1)<<'\n';
				flag[i] = flag[r] = true;
				s.insert(a[i].substr(a[i].size() - k - 1));
				val = solve(i+1, count+2);
				if(val > max_val)
					max_val = val;
				flag[i] = flag[r] = false;
				s.erase(a[i].substr(a[i].size() - k - 1));

			}
		}
	}

	return max_val;
}

int main()
{
	int t, i, val = 1;

	cin>>t;

	while(t--)
	{
		cin>>n;
		a.clear();
		flag.clear();
		s.clear();

		a.resize(n);
		flag.assign(n, false);

		for(i = 0;i < n;i++)
			cin>>a[i];

		printf("Case #%d: ",val);
		cout<<solve(0, 0)<<'\n';
		val++;
	}
}
