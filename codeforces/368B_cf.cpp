#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;


int comp1(pair<int, int> a, pair<int, int> b)
{
	if(b.first > a.first)
		return 1;
	else
		return 0;
}


int comp2(pair<int, int> a, pair<int, int> b)
{
	if(b.second > a.second)
		return 1;
	else
		return 0;
}


int main()
{
	int n, m, i, j;
	set<int> s;
	vector<pair<int, int> >l, c;

	cin>>n>>m;

	int a[n];
	l.resize(m);
	c.resize(m);

	for(i = 0;i < n;i++)
	{
		cin>>a[i];
	}

	for(i = 0;i < m;i++)
	{
		cin>>l[i].first;
		l[i].second = i;
	}

	sort(l.begin(), l.end(), comp1);

	int start, end;

	start = l[m-1].first;
	end = n;

	i = m-1;

	while(i >= 0)
	{
		for(j = start-1;j <= end-1;j++)
			s.insert(a[j]);

		//cout<<start<<" "<<end<<'\n';

		c[i].first = s.size();
		c[i].second = l[i].second;
		i--;
		end = start;
		if(i >= 0)
			start = l[i].first;
	}

	sort(c.begin(), c.end(), comp2);



	for(i = 0;i < m;i++)
		cout<<c[i].first<<"\n";
	//cout<<'\n';

	return 0;
}
