#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int a, b, ct;

bool check(const int &r, const int &c, const vector<int> &q)
{

	for(int i = 0;i < c;i++)
	{
		if(r == q[i] || abs(r - q[i]) == abs(c - i))
		{
			return false;
		}
	}

	return true;
}


void solve(vector<int> &q, int col)
{
	int i;
	if(col == q.size())
	{
		if(q[b-1] != a-1)
			return;

		printf("%2d      ", ct);
		ct++;

		for(i = 0;i < q.size();i++)
		{
			if(i != 0)
				cout<<" ";
			cout<<q[i]+1;
		}
		cout<<'\n';
	}

	for(i = 0;i < q.size();i++)
	{
		if(check(i, col, q))
		{
			q[col] = i;
			solve(q, col+1); 
		}
	}
}


int main()
{
	int t, ctt = 0;
	vector<int> q(8);
	cin>>t;

	while(t--)
	{
		if(ctt != 0)
			cout<<'\n';

		cout<<"SOLN       COLUMN\n";
		cout<<" #      1 2 3 4 5 6 7 8\n\n";
		cin>>a>>b;
		ct = 1;

		solve(q, 0);
		ctt++;
	}

	return 0;
}
