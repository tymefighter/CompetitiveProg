#include<iostream>
#include<utility>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int k, x, y;
	int a, b;
	vector<pair<int, int> >arr;

	while(cin>>k)
	{
		arr.clear();
		for(y = k+1; y <= 2*k;y++)
		{
			a = k * y;
			b = y - k;

			if(a%b == 0)
			{
				arr.push_back(make_pair(a/b, y));
			}
		}

		cout<<arr.size()<<'\n';

		for(auto it = arr.begin();it != arr.end();it++)
			printf("1/%d = 1/%d + 1/%d\n", k, (*it).first, (*it).second);
	}
	return 0;
}
