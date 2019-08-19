#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

int main()
{
	int q, q_type, cost;
	stack<int> s;

	cin>>q;

	while(q--)
	{
		cin>>q_type;

		if(q_type == 1)
		{
			if(s.empty())
				cout<<"No Food\n";
			else
			{
				cout<<s.top()<<'\n';
				s.pop();
			}
		}
		else
		{
			cin>>cost;
			s.push(cost);
		}
	}
	return 0;
}
