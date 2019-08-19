#include<iostream>
#include<vector>
#include<set>

using namespace std;

void subsets(vector<int> &a, int idx, multiset<int> &s)
{
	if(idx >= a.size())
		return;

	if(idx == a.size() - 1)
	{
		for(auto it = s.begin(); it != s.end(); it++)
			cout<<*it<<" ";
		cout<<'\n';
	}



	s.insert(a[idx]);
	subsets(a, idx+1, s);
	s.erase(a[idx]);
	subsets(a, idx+1, s);
}

int main()
{
	int n;
	vector<int> a;
	multiset<int> s;

	cin>>n;
	a.resize(n);

	for(int i = 0;i < n;i++)
		a[i] = i+1;

	subsets(a, 0, s);

	return 0;
}
