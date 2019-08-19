#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<string>
#include<cassert>

using namespace std;

int main()
{
	int i, n, val, x, Q;
	string str;
	queue<int> q;
	stack<int> s;

	cin>>n;

	for(i = 0;i < n;i++)
	{
		cin>>val;
		q.push(val);
	}

	cin>>Q>>x;

	val = 0;

	if(val == x)
	{
		cout<<"0\n";
		return 0;
	}

	for(i = 0;i < Q;i++)
	{
		cin>>str;



		if(str == "Harry")
		{

			val += q.front();
			s.push(q.front());
			q.pop();
		}
		else
		{
			val -= s.top();
			s.pop();
		}

		if(val == x)
		{
			cout<<s.size()<<'\n';
			break;
		}
	}

	//assert(val == x);
	if(val != x)
	{
		cout<<"-1\n";
	}

	return 0;
}
