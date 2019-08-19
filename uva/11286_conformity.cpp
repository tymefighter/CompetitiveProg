#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;


int main()
{
	int n, i, max_val = 0, count = 0;
	map<string, int> m;
	stringstream ss;
	vector<string> a(5);
	string s;

	while(cin>>n)
	{
		if(n == 0)
			break;

		max_val = 0;
		m.clear();

		while(n--)
		{
			for(i = 0;i < 5;i++)
				cin>>a[i];
		
			sort(a.begin(), a.end());
			ss.str("");

			for(auto x : a)
			{
				ss<<x;
			}
			s = ss.str();
			


			if(m.count(s) == 0)
				m[s] = 0;
			
			m[s] += 1;

			if(m[s] > max_val)
			{
				max_val = m[s];
			}

		}

		count = 0;

		for(auto it = m.begin(); it != m.end(); it++)
		{
			if((*it).second == max_val)
			{
				//cout<<(*it).second<<'\n';
				count += (*it).second;
			}
		}
		cout<<count<<'\n';

	}

	return 0;
}
