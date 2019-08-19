#include<iostream>
#include<vector>
#include<map>
#include<utility>

using namespace std;

map<pair<long long int, long long int>, int> m;


int solve(int pl, long long int a, long long int b)
{
	if(b > a)
		swap(a, b);

	//cout<<a<<" "<<b<<'\n';

	if(m.find({a, b}) != m.end())
	{
		if(m[make_pair(a, b)] == 0)
			return pl;
		else
			return (pl + 1) % 2;
	}


	if(a % b == 0)
	{
		m[make_pair(a, b)] = 0;
		return pl;
	}

	long long int x = b;


	if(solve((pl + 1) % 2, a%b, b) == pl)
	{
		m[make_pair(a, b)] = 0;
		return pl;
	}
	else if((((a%b) + b) < a) && (solve((pl + 1) % 2, (a%b) + b, b) == pl))
	{
		m[make_pair(a, b)] = 0;
		return pl;
	}

	
	m[make_pair(a, b)] = 1;
	return (pl + 1) % 2;
}


int main()
{
	int t;
	long long a, b;

	cin>>t;

	while(t--)
	{
		cin>>a>>b;
		if(a > b)
			swap(a, b);
		
		m.clear();
		if(solve(0, a, b) == 0)
			cout<<"Ari\n";
		else
			cout<<"Rich\n";
			
	}

	return 0;
}
