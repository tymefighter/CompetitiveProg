#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int n, k;
unordered_map<string, int> m;
vector<string> a;

void reset()
{
	m.clear();
	a.clear();
	a.resize(n);
}

void read()
{
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
		m[a[i]] = i;
	}
}

char sym[] = {'S', 'E', 'T'};

void solve()
{
	int i, j, p, ans = 0;
	
	string s;
	s.clear();
	s.resize(k);

	for(i = 0;i < n;i++)
	{
		for(j = i + 1;j < n;j++)
		{
			for(p = 0;p < k;p++)
			{
				if(a[i][p] == a[j][p])
					s[p] = a[i][p];
				else
				{
					for(int q = 0;q < 3;q++)
					{
						if(sym[q] != a[i][p] && sym[q] != a[j][p])
						{
							s[p] = sym[q];
							break;
						}
					}
				}
			}
			if(m.find(s) != m.end() && m[s] > j)
				ans ++;
		}	
	}
	
	cout<<ans<<"\n";
}

int main()
{
	cin>>n>>k;
	reset();
	read();
	solve();
	return 0;
}
