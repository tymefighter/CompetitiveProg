#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<vector<int> > succ(const vector<vector<int> > &a)
{
	vector<vector<int> > b = a;

	b[0][0] = a[0][1]^a[1][0];
	b[0][1] = a[0][0]^a[0][2]^a[1][1];
	b[0][2] = a[0][1]^a[1][2];
	b[1][0] = a[0][0]^a[1][1]^a[2][0];
	b[1][1] = a[0][1]^a[1][2]^a[2][1]^a[1][0];
	b[1][2] = a[0][2]^a[1][1]^a[2][2];
	b[2][0] = a[1][0]^a[2][1];
	b[2][1] = a[2][0]^a[1][1]^a[2][2];
	b[2][2] = a[2][1]^a[1][2];

	return b;

}

bool check(const vector<vector<int> > &a, const vector<vector<int> > &b)
{
	int i, j;
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
		{
			if(a[i][j] != b[i][j])
				return false;
		}
	}

	return true;
}

int main()
{
	int t, i, j;
	char ch;
	bool rep;
	vector<vector<int> > a(3);
	vector<vector<vector<int> > > x;

	for(i = 0;i < 3;i++)
		a[i].resize(3);

	cin>>t;

	while(t--)
	{
		x.clear();

		for(i = 0;i < 3;i++)
		{
			for(j = 0;j < 3;j++)
			{
				cin>>ch;
				a[i][j] = ch - '0';
				//cout<<a[i][j]<<' ';////
			}
		}
		//cout<<'\n';/////

		x.push_back(a);
		rep = false;

		while(rep == false)
		{
			a = succ(a);

			for(i = 0;i < x.size();i++)
			{
				if(check(a, x[i]) == true)
				{
					cout<<i-1<<'\n';
					rep = true;
					break;
				}
			}

			x.push_back(a);
		}
	}

	return 0;
}
