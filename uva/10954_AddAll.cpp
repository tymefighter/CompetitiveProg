#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int> > pq;
	int n, i, x, a, b, val;

	while(cin>>n)
	{
		if(n == 0)
			break;
	

		val = 0;
		for(i = 0;i < n;i++)
		{
			cin>>x;
			pq.push(x);
		}

		while(pq.size() > 1)
		{
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();

			pq.push(a+b);
			val += a+b;
		}
		pq.pop();
		cout<<val<<'\n';
	}

	return 0;
}
