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
map<int, int> m_val;

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
	int i, x, y, j;
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
	for(j = 0;j < m_val[0]-1; j++)
	{
		order.push_back(x);
		order.push_back(y);
	}

	if(x == y && m_val[0] > 1)
		order.push_back(x);

	
	for(i = 1;i < a.size();i++)
	{
		if(a[i] % x == 0)
		{
			y = a[i] / x;
			order.push_back(y);
			printf("%d %d %d %d -- %d \n", x, y, a[i], m_val[a[i]], i);
			for(j = 0;j < m_val[i]-1; j++)
			{
				order.push_back(x);
				order.push_back(y);
			}

			if(x == y && m_val[i] > 1)
				order.push_back(x);
		}

		else if(a[i] % y == 0)
		{
			x = y;
			y = a[i] / x;
			order.push_back(y);
			for(j = 0;j < m_val[i]-1; j++)
			{
				order.push_back(x);
				order.push_back(y);
			}

			if(x == y && m_val[i] > 0)
				order.push_back(x);
		}
		s.insert(x);
		s.insert(y);
	}

	i = 0;
	for(int u : s)
	{
		//cout<<u<<" ";
		m[u] = 'A' + i;
		i++;
	}
	//cout<<'\n';
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
	int t, n, l, i, count = 1, val, prev_val = -1;
	cin>>t;

	while(t--)
	{
		cin>>n>>l;
		prev_val = -1;
		clear_all();

		for(i = 0;i < l;i++)
		{
			cin>>val;
			if(val != prev_val)
			{
				a.push_back(val);
				m_val[a.size()-1] = 0;
			}
			else
			{
				m_val[a.size()-1] += 1;
				cout<<a.size()-1<<" "<<m_val[a.size()-1]<<'\n';
			}
			prev_val = val;
		}
		
		//print_vec(a);
		SieveOfEratosthenes(n);
		//print_vec(is_prime);
		printf("Case #%d: ", count);
		solve();
		count++;
	}

	return 0;
}
