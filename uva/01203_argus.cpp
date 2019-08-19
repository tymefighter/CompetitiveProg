#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<map>

using namespace std;

int main()
{
	int code, time, k;
	pair<int, int> x;
	string s;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	map<int, int> m;
	
	while(cin>>s)
	{
		if(s[0] == '#')
			break;
		cin>>code>>time;
		pq.push(make_pair(time, code));
		m[code] = time;
		//printf("%d %d\n",code, time);
	}

	cin>>k;
	while(k--)
	{
		x = pq.top();
		pq.pop();
		time = x.first;
		code = x.second;
		time += m[code];

		printf("%d\n",code);
		pq.push(make_pair(time, code));
	}

	return 0;
}
