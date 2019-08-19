#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

int comp(pair<int, string> a, pair<int, string> b)
{
	if(a.first < b.first)
		return 1;
	else if(a.first > b.first)
		return 0;
	else
	{
		if(a.second < b.second)
			return 1;
		else
			return 0;
	}
}

int main()
{
	int t, age;
	string name;
	vector<pair<int, string> > list;

	cin>>t;
	while(t--)
	{
		cin>>age>>name;
		list.push_back(make_pair(age, name));
	}

	sort(list.begin(), list.end(), comp);

	for(int i = 0;i < list.size();i++)
	{
		cout<<list[i].second<<'\n';
	}

	return 0;
}
