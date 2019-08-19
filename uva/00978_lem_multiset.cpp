#include<iostream>
#include<cstdio>
#include<set>
#include<vector>

using namespace std;

int main()
{
	vector<int> v1, v2;
	multiset<int, greater<int> > s1, s2;
	int t, i, n1, n2, c, num, b, count = 0;

	cin>>t;
	while(t--)
	{
		if(count != 0)
			cout<<'\n';
		cin>>b>>n1>>n2;
		s1.clear();
		s2.clear();

		for(i = 0;i < n1;i++)
		{
			cin>>c;
			s1.insert(c);
		}

		for(i = 0;i < n2;i++)
		{
			cin>>c;
			s2.insert(c);
		}
		
		while(!s1.empty() && !s2.empty())
		{
			num = min((int)min(s1.size(), s2.size()), b);
			v1.clear();
			v2.clear();
			auto it1 = s1.begin();
			auto it2 = s2.begin();
			//printf("%d\n",num); ///////
			for(i = 0;i < num; i++)
			{
				v1.push_back(*it1);
				v2.push_back(*it2);
				s1.erase(it1++);
				s2.erase(it2++);
			}

			for(i = 0;i < v1.size();i++)
			{
				//printf("%d %d - ",v1[i], v2[i]);
				if(v1[i] - v2[i] < 0)
				{
					s2.insert(v2[i] - v1[i]);
				}
				else if(v1[i] - v2[i] > 0)
				{
					s1.insert(v1[i] - v2[i]);
				}
			}
			//cout<<'\n';////
		}

		if(s1.empty() && s2.empty())
			printf("green and blue died\n");
		else if(s1.empty())
		{
			printf("blue wins\n");
			
			for(auto it = s2.begin(); it != s2.end(); it++)
			{
				cout<<*it<<'\n';
			}
		}
		else
		{
			printf("green wins\n");

			for(auto it = s1.begin(); it != s1.end(); it++)
			{
				cout<<*it<<'\n';
			}
		}
		count++;
	}

	return 0;
}
