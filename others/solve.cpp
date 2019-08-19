#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<utility>

using namespace std;

vector<vector<bool> >arr;
stack<pair<int, int> > st;
int m, n;



bool solve(int a, int b, int count)
{
	int r, c;

	if(count == m*n)
	{
		return true;
	}

	for(r = 0;r < m;r++)
	{
		for(c = 0;c < n;c++)
		{
			if((arr[r][c] == false) && (((a != r) && (b != c) && ((r - c) != (a - b)) && ((r + c) != (a + b))) || (a == -1 && b == -1)))
			{
				arr[r][c] = true;
				if(solve(r, c, count+1))
				{
					st.push({r, c});
					return true;
				}
				arr[r][c] = false;
			}
		}
	}

	return false;
}

int main()
{
	int t, val = 1;

	cin>>t;

	while(t--)
	{
		cin>>m>>n;
		arr.clear();
		arr.assign(m, vector<bool> (n));
		if(solve(-1, -1, 0))
		{
			printf("Case #%d: POSSIBLE\n", val);
			while(st.empty() == false)
			{
				cout<<st.top().first+1<<" "<<st.top().second+1<<'\n';
				st.pop();
			}
		}
		else
		{
			printf("Case #%d: IMPOSSIBLE\n", val);
		}

		val++;
	}

	return 0;
}
