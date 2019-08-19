#include<iostream>
#include<cmath>

using namespace std;

long long int n, e;
double power;

void solve()
{
    e = 0;
    power = 1;
    int t_dig, h_dig, s_dig, temp_dig;
    long long int prefix;

    s_dig = (int)log10((double)n) + 1;

    while(true)
    {
        t_dig = 0;
        while(power > 1e30)
        {
            power /= 10;
            t_dig ++;
        }
        
        temp_dig = (int)log10(power) + 1;
        t_dig += temp_dig;
        h_dig = t_dig - s_dig;
        
        if(h_dig <= s_dig)
        {
            power *= 2;
            e++;
            continue;
        }

        prefix = power / pow(10, temp_dig - s_dig);
        if(prefix == n)
        {
            cout<<e<<"\n";
            return;
        }

        power *= 2;
        e++;
    }
    
}

int main()
{
    while(cin>>n)
        solve();
    return 0;
}