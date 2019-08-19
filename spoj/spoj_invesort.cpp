#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<queue>
#include<cmath>

using namespace std;

void invert(string &a, int start, int end)
{
	for(int i = 0;i <= (end - start)/2;i++)
		swap(a[start + i], a[end - i]);
	
	return;
}

int solve(map<string, int> &m, queue<string> &q, const string &a, const string &b)
{
	string x, y;
	m[a] = 0;
	int i, j;
	q.push(a);


	while(q.empty() == false) 
	{
		y = x = q.front();
		q.pop();

		
		if(x == b)
			return m[x];

		for(i = 0;i < 10;i++)
		{
			if(x[i] == b[i])
				continue;
			for(j = i+1;j < 10;j++)
			{
				if(x[j] == b[j])
					break;

				invert(y, i, j);
				//cout<<y<<'\n';

				if(m.count(y) == 0)
				{
					m[y] = m[x] + 1;
					cout<<m[y]<<'\n';
					if(y == b)
					{
						return m[y];
					}
					q.push(y);
				}

				invert(y, i, j);
			}
		}
	}

	return m[y];
}

int main()
{
	string a, b;
	map<string, int> m;
	queue<string> q;

	while(cin>>a>>b)
	{
		if(a[0] == '*')
			break;

		m.clear();
		
		while(q.empty() == false)
			q.pop();

		cout<<solve(m, q, a, b)<<'\n';
	}

	return 0;
}
