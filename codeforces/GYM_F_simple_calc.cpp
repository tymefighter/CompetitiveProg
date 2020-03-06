#include<iostream>
#include<cstdio>

using namespace std;

long long n, k;
FILE *frd, *frw;

long long computePow(long long x, long long pw, long long mod_val)
{
    if(pw == 0)
        return 1;
    else if(pw % 2 == 1)
    {
        long long val = computePow(x, pw - 1, mod_val) * x;
        if(mod_val != -1)
            val %= mod_val;
        return val;
    }
    else
    {
        long long val = computePow(x, pw / 2, mod_val);
        val *= val;
        if(mod_val != -1)
            val %= mod_val;
        return val;
    }
}

void solve()
{
    long long pw;
    if(n <= 20)
    {
        pw = computePow(2, n, -1);
    }
    else
    {
        pw = 2;
        long long phi_k = k, k_temp = k;
        
        for(int i = 2;i * (long long)i <= k_temp;i++)
        {
            if(k_temp % i)
                continue;

            phi_k -= phi_k / i;
            while(k_temp % i == 0)
                k_temp /= i;
        }

        if(k_temp != 1)
            phi_k -= phi_k / k_temp;

        pw = phi_k + computePow(2, n, phi_k);
    }

    long long ans = (computePow(2, pw, k) + 1) % k;
    fprintf(frw, "%lld\n", ans);
}

int main()
{
    frd = fopen("calc.in", "r");
    if(frd == NULL)
        return 0;
    frw = fopen("calc.out", "w");
    if(frd == NULL)
        return 0;
    fscanf(frd, "%lld %lld", &n, &k);
    solve();

    fclose(frd);
    fclose(frw);

    return 0;
}