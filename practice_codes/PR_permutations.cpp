#include<iostream>
#include<vector>

using namespace std;

void printVec(vector<int> a)
{
	for(int i = 0; i < a.size();i++)
		cout<<a[i]<<" ";
	cout<<'\n';

	return;
}

void permute(vector<int> a, int idx)
{
	int i, j;

	if(idx == a.size()-1)
		printVec(a);

	if(idx >= a.size())
		return;

	for(i = idx;i < a.size();i++)
	{
		swap(a[idx], a[i]);
		permute(a, idx+1);
		swap(a[idx], a[i]);
	}

	return;
}


int main()
{
	int n;
	vector<int> a;

	cin>>n;
	a.resize(n);

	for(int i = 0;i < a.size();i++)
		a[i] = i+1;

	permute(a, 0);
	return 0;
}
