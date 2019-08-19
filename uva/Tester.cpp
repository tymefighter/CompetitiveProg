#include<iostream>
#include<queue>

using namespace std;

queue<int> q;
int n;

void get_ans()
{
	for(int i = 1;i <= n;i++)
		q.push(i);

	int u;
	while(q.size() > 1)
	{	
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout<<q.front()<<"\n";
	q.pop();
}

int main()
{
	while(cin>>n)
	{
		if(!n)
			break;
		get_ans();
	}
	return 0;
}