#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>

using namespace std;

int main()
{
	queue<int> q;
	priority_queue<int> pq;
	stack<int> s;
	int n, i, flag_q, flag_pq, flag_s, query, x, a;

	while(cin>>n)
	{
		flag_q = flag_pq = flag_s = true;
		for(i = 0;i < n;i++)
		{
			cin>>query>>x;
			if(query == 1)
			{
				q.push(x);
				pq.push(x);
				s.push(x);
			}
			else
			{
				if(!q.empty())
				{
					a = q.front();
					q.pop();
					if(a != x)
						flag_q = false;

					a = pq.top();
					pq.pop();
					if(a != x)
						flag_pq = false;

					a = s.top();
					s.pop();
					if(a != x)
						flag_s = false;
				}
				else
				{
					flag_q = flag_pq = flag_s = false;
				}
			}
		}

		if( (flag_s & flag_pq) || (flag_s & flag_q) || (flag_pq & flag_q))
			printf("not sure\n");
		else if(flag_q == true)
			printf("queue\n");
		else if(flag_pq == true)
			printf("priority queue\n");
		else if(flag_s == true)
			printf("stack\n");
		else
			printf("impossible\n");

		while(!q.empty() || !pq.empty() || !s.empty())
		{
			if(!q.empty())
				q.pop();
			if(!pq.empty())
				pq.pop();
			if(!s.empty())
				s.pop();
		}
	}

	return 0;
}
