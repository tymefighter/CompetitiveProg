#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> a;
int m;

void read()
{
	a.resize(m);
	for(int i = 0;i < m;i++)
		cin>>a[i];
}

int dist(int r1, int c1, int r2, int c2)
{
	return abs(r1 - r2) + abs(c1 - c2);
}

int solve()
{
	int r1, c1, r2, c2, max_out, min_in, dist_val;
	int i, j;
	max_out = 0;
	for(i = 0;i < m*m;i++)
	{
		r1 = i / m;
		c1 = i % m;
		
		if(a[r1][c1] != '1')
			continue;
		
		min_in = -1;

		for(j = 0;j < m*m;j++)
		{
			r2 = j / m;
			c2 = j % m;
			
			if(a[r2][c2] != '3')
				continue;

			dist_val = dist(r1, c1, r2, c2);
			if(min_in == -1 || dist_val < min_in)
				min_in = dist_val;
		}

		if(max_out < min_in)
			max_out = min_in;
	}

	return max_out;
}

int main()
{
	while(cin>>m)
	{
		read();
		cout<<solve()<<'\n';
	}

	return 0;
}
