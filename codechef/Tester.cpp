#include<iostream>
#include<string>

using namespace std;

const long long int MOD = 1000000007;
int nl, nr, l, r;

long long int pow(int n)
{
    if(n == 0)
        return 1;
    if(n % 2)
        return (pow(n - 1) * 10) % MOD;
    else
    {
        long long int val = pow(n / 2);
        return (val * val) % MOD;
    }
}


long long int get_ans(int x)
{
	int prev = -1, dig, i = 0;
	long long int val = 0;
	while(x)
	{
		dig = x % 10;
		if(dig == prev)
			val =  (val - dig * pow(i - 1)) % MOD;
		
		val = (val + dig * pow(i)) % MOD;

		i++;
		prev = dig;
		x /= 10;
	}
	return val;
}

void solve()
{
	long long int ans = 0;
	for(int i = l;i <= r;i++)
		ans = (ans + get_ans(i)) % MOD;

	cout<<ans<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>nl>>l;
		cin>>nr>>r;
		solve();
	}
	return 0;
}