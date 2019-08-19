#include<iostream>
#include<vector>


using namespace std;

int n;
bool is_prime[1000005];
vector<int> primes;

void sieve_er()
{
	int i, j;
	for(i = 0;i < 1000001;i++)
		is_prime[i] = true;
	primes.clear();
	
	for(i = 2;i <= 1000000;i++)
	{
		if(!is_prime[i])
			continue;
			
		if(i * (i * 1ll) > 1000000)
		{
			primes.push_back(i);
			continue;
		}
		for(j = i * i;j <= 1000000;j += i)
			is_prime[j] = false;
		if(i != 2)
			primes.push_back(i);
	}	
}

void solve()
{
	int l = 0, r = primes.size() - 1, val;
	
	while(l <= r)
	{
		val = primes[l] + primes[r];
		if(val == n)
		{
			printf("%d = %d + %d\n", n, primes[l], primes[r]);
			return;
		}
		else if(val > n)
			r--;
		else
			l++;
	}
	
	cout<<"Goldbach's conjecture is wrong.\n";
}


int main()
{
	sieve_er();
	while(cin>>n)
	{
		if(!n)
			break;
		solve();
	}
	return 0;
}
