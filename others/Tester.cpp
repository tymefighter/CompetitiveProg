#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>

using namespace std;

vector<bool> is_prime;
vector<int> prime;
map<char, int> m;

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


int main()
{
	int n, i;
	string s;
	cin>>n;
	cin>>s;

	SieveOfEratosthenes(n);
	
	for(i = 0;i < 26;i++)
		m['A' + i] = prime[i+3];
	
	for(i = 0;i < s.size()-1;i++)
	{
		cout<<m[s[i]] * m[s[i+1]]<<" ";
	}
	cout<<'\n'<<s.size()-1<<'\n';

}
