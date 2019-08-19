#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<set>
#include<map>

using namespace std;

vector<bool> is_prime;
vector<int> prime;
vector<int> a;
vector<int> order;
set<int> s;
map<int, char> m;

void clear_all()
{
	is_prime.clear();
	prime.clear();
	a.clear();
	order.clear();
	s.clear();
	m.clear();
}

/*void print_vec(const vector<int> &vec)
{
	for(int x : vec)
	{
		cout<<x<<" ";
	}
	cout<<'\n';
}*/

void SieveOfEratosthenes(int n) 
{
	is_prime.assign(n+1, true);

	for (int p=2; p*p<=n; p++) 
	{  
		if (is_prime[p] == true) 
		{ 
			for (int i=p*p; i<=n; i += p) 
				is_prime[i] = false; 
		} 
    }

	for (int p=2; p<=n; p++) 
	{
		if(is_prime[p])
		{
			prime.push_back(p);
		}
	}

	return;
}

void solve()
{
	int i, x, y;
	x = y = -1;

	for(i = 0;i < prime.size();i++)
	{
		if(a[0] % prime[i] == 0)
		{
			x = prime[i];
			y = a[0] / prime[i];
			break;
		}
	}
	
	s.insert(x);
	s.insert(y);

	if(a[1] % x == 0)
		swap(x, y);

	order.push_back(x);
	order.push_back(y);
	
	
	for(i = 1;i < a.size();i++)
	{
		if(a[i] % x == 0)
		{
			y = a[i] / x;
			order.push_back(y);
		}
		else if(a[i] % y == 0)
		{
			x = y;
			y = a[i] / x;
			order.push_back(y);
		}
		s.insert(x);
		s.insert(y);
	}

	i = 0;
	for(int u : s)
	{
		cout<<u<<" ";
		m[u] = 'A' + i;
		i++;
	}
	cout<<'\n';
	for(i = 0;i < order.size()-1;i++)
		cout<<order[i]*order[i+1]<<" ";

	for(int u : order)
	{
		//cout<<u<<" ";
		cout<<m[u];
	}
	cout<<'\n';

	return;
}

int main()
{
	int t, n, l, i, count = 1;
	cin>>t;

	while(t--)
	{
		cin>>n>>l;

		clear_all();

		a.resize(l);

		for(i = 0;i < l;i++)
			cin>>a[i];

		//print_vec(a);
		SieveOfEratosthenes(n);
		//print_vec(is_prime);
		printf("Case #%d: ", count);
		solve();
		count++;
	}

	return 0;
}
