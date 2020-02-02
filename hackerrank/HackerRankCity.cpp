#include<iostream>

using namespace std;

const int N = 1000005;
const long long MOD = 1e9 + 7;
int n;
long long a[N], d[N], p[N], x[N], v[N];

void read()
{
    cin>>n;
    for(int i = 1;i <= n;i++)
        cin>>a[i];
}

void solve()
{
    d[0] = 0;
    p[0] = 0;
    x[0] = 0;
    v[0] = 1;

    for(int i = 1;i <= n;i++)
    {
        // Actual formula
        //d[i] = 4 * d[i - 1] + 4 * (2 * x[i - 1] + 3 * v[i - 1] * a[i]) + a[i]
        //    + 2 * (2 * v[i - 1] * x[i - 1] + 2 * v[i - 1] * v[i - 1] * a[i])
        //    + 4 * (2 * v[i - 1] * x[i - 1] + 3 * v[i - 1] * v[i - 1] * a[i]);
        
        d[i] = (4 * d[i - 1] + 8 * x[i - 1]) % MOD;
        d[i] = (d[i] + 12 * ((v[i - 1] * a[i]) % MOD) + a[i]) % MOD;
        d[i] = (d[i] + 12 * ((v[i - 1] * x[i - 1]) % MOD)) % MOD;
        d[i] = (d[i] + 16 * ((((v[i - 1] * v[i - 1]) % MOD) * a[i]) % MOD)) % MOD; 
        
        //p[i] = 2 * p[i - 1] + 3 * a[i];
        
        p[i] = (2 * p[i - 1] + 3 * a[i]) % MOD;

        //x[i] = 4 * x[i - 1] + a[i] * (8 * v[i - 1] + 3) + p[i - 1] * (3 * v[i - 1] + 2);
		
		x[i] = (4 * x[i - 1] + a[i] * ((8 * v[i - 1] + 3) % MOD)) % MOD;
		x[i] = (x[i] + p[i - 1] * ((3 * v[i - 1] + 2) % MOD)) % MOD;

        //v[i] = 4 * v[i - 1] + 2;
		
		v[i] = (4 * v[i - 1] + 2) % MOD;
		

        //cout<<d[i]<<" "<<p[i]<<" "<<x[i]<<" "<<v[i]<<"\n";
    }

    cout<<d[n]<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}
