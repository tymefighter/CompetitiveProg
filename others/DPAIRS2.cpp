#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	return;
}

void swap(vector<int> &a, vector<int> &b)
{
	vector<int> temp = a;
	a = b;
	b = temp;
	return;
}

int main()
{
	bool flag = false;
	int n, m, i;
	vector<int> a, b;
	map<int, int> m1, m2;

	cin>>n>>m;

	a.resize(n);
	b.resize(m);

	for(i = 0;i < n;i++)
	{
		cin>>a[i];
		m1[a[i]] = i;
	}

	for(i = 0;i < m;i++)
	{
		cin>>b[i];
		m2[b[i]] = i;
	}

	if(m > n)
	{
		swap(n, m);
		swap(a, b);
		flag = true;
	}


	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for(i = 0;i <= m-2;i++)
	{

		if(flag == false)
		{
			cout<<m1[a[i]]<<" "<<m2[b[i]]<<'\n';
			cout<<m1[a[i+1]]<<" "<<m2[b[i]]<<'\n';
		}
		else
		{
			cout<<m1[b[i]]<<" "<<m2[a[i]]<<'\n';
			cout<<m1[b[i]]<<" "<<m2[a[i+1]]<<'\n';
		}
		//cout<<a[i]+b[i]<<'\n';
		//cout<<a[i+1]+b[i]<<'\n';
	}

	for(i = m-1;i < n;i++)
	{
		if(flag == false)
		{
			cout<<m1[a[i]]<<" "<<m2[b[m-1]]<<'\n';
		}
		else
		{
			cout<<m1[b[m-1]]<<" "<<m2[a[i]]<<'\n';
		}
		//cout<<a[i]+b[m-1]<<'\n';
	}

	//cout<<m2[3]<<"----\n";
	return 0;
}
