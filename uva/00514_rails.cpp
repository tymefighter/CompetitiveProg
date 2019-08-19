#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	stack<int> s;
	int n, x, i, j;
	vector<int> a;
	bool exit = false;

	while(cin>>n)
	{
		if(n == 0)
			break;
		
		a.clear();
		a.resize(n);
		exit = false;
		while(exit == false)
		{
			while(s.empty() == false)
				s.pop();
			cin>>a[0];
			x = 1;

			if(a[0] == 0)
			{
				exit = true;
				break;
			}
			
			for(i = 1;i < n;i++)
				cin>>a[i];


			i = 0;
			j = 1;

			while(j <= n)
			{
				//printf("%d %d %d - ",i, a[i], j);///
				if(a[i] == j)
				{
					//cout<<i<<' ';
					i++;
					j++;
				}
				else if(s.empty() == false)
				{
					if(s.top() == a[i])
					{
						s.pop();
						i++;
					}
					else
					{
						s.push(j);
						j++;
					}
				}
				else
				{
					s.push(j);
					j++;
				}
			}

			if(i == n)
				cout<<"Yes\n";
			else
			{
				while(s.empty() == false)
				{
					if(s.top() != a[i])
					{
						break;
					}
					
					s.pop();
					i++;
				}

				if(s.empty() == false)
					cout<<"No\n";
				else
					cout<<"Yes\n";
			}
		}
		cout<<'\n';
	}
}
