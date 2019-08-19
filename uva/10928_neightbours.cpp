#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<sstream>

using namespace std;

void getNo(string &str, int &x)
{
	stringstream ss(str);

	ss>>x;

	return;
}

void getArr(string &str, vector<int> &a)
{
	stringstream ss(str);
	int x;

	a.clear();
	//cout<<str<<'\n';

	while(ss)
	{
		ss>>x;
		//cout<<x<<" ";
		a.push_back(x);
	}
	

	//cout<<"\n";
	return;
}


int main()
{
	string str;
	set<int> s;
	vector<int> a;
	int n, p, i, min, idx;

	//cin>>n;
	getline(cin, str);
	getNo(str, n);
	//cout<<n<<"!!\n";


	while(n--)
	{
		//cin>>p;

		str.clear();
		while(str == "")
			getline(cin, str);

		//getline(cin, str);
		getNo(str, p);
		//cout<<p<<"----\n";
	
		
		idx = 1;
		//cout<<p<<"--\n";
		getline(cin, str);
		//cout<<str<<'\n';
		getArr(str, a);
		
		min = a.size();
		s.insert(idx);
		//cout<<str<<" "<<a.size()<<"-\n";


		for(i = 1;i < p;i++)
		{
			getline(cin, str);
			//cout<<str<<'\n';
			getArr(str, a);
			//cout<<str<<" "<<a.size()<<"-\n";

			idx++;
	
			if(min == a.size())
				s.insert(idx);
			else if(min > a.size())
			{
				s.clear();
				min = a.size();
				s.insert(idx);
			}
		}

		for(auto it = s.begin(); it != s.end(); it++)
		{

			if(it != s.begin())
				cout<<" ";
			cout<<*it;
		}
		cout<<'\n';

		s.clear();
	}

	return 0;
}
