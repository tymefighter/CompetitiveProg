#include<iostream>
#include<vector>
/*
    Codechef problem
    This problem has not yet been solve
 */
using namespace std;

int solve(const vector<int> &a,const int &yb,const int &mb,const int &db,const int &yc,const int &mc,const int &dc)
{
	int i;
	int ys = (yc/4) - (yb/4);

	if(yb%4 == 0)
		ys++;

	int num_leaps = max(ys - (yc%4 == 0 ? 1:0) - (yb%4 == 0 ? 1:0), 0);

	int days_year = 0;
	for(i = 0;i < a.size();i++)
		days_year += a[i];

	int d = days_year*(yc - yb - 1);

	int b1 = a[mb-1] - db + 1, b2 = 0;

	for(i = mb;i < a.size();i++)
	{
		b2 += a[i];
	}

	int a1 = dc, a2 = 0;

	for(i = 0;i <= mc-2;i++)
	{
		a2 += a[i];
	}

	if(yb%4 == 0)
		b1++;
	if(yc%4 == 0 && mc == a.size() && dc == a[a.size()-1]+1)
		b2++;

	//cout<<d<<" "<<b1<<" "<<b2<<" "<<a1<<" "<<a2<<" "<<num_leaps<<'\n';
	d += b1 + b2 + a1 + a2 + num_leaps;
	return d;
}


int main()
{
	int t, n, i;
	int yb, mb, db;
	int yc, mc, dc;
	vector<int> a;


	cin>>t;

	while(t--)
	{
		cin>>n;
		a.resize(n);
		for(i = 0;i < n;i++)
			cin>>a[i];

		cin>>yb>>mb>>db;
		cin>>yc>>mc>>dc;
		cout<<solve(a, yb, mb, db, yc, mc, dc)<<'\n';
	}
	return 0;
}
