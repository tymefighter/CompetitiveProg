#include<iostream>
#include<cmath>

using namespace std;

long long int a, b, l, r;
long long int n1, n2, val1, val2;
long long int lcm_val;
long long int PS, other;

void read()
{
    cin>>a>>b>>l>>r;

    long long int ta, tb;
    ta = max(l, r);
    tb = min(l, r);

    r = ta;
    l = tb;
}

long long int gcd(long long int x, long long int y)
{
    if(x > y)
        swap(x, y);
    
    if(x == 0)
        return y;
    
    return gcd(y % x, x);
}

long long int lcm(long long int x, long long int y)
{
    return (x * y) / gcd(x, y);
}

long long int get_val(long long int x)
{
    return (((n2 * (n2 + 1)) / 2) - ((n1 * (n1 - 1)) / 2)) * x;
}

void solve()
{
    if(l > r)
    {
        PS = 0;
        other = 0;
        cout<<"TRUE LOVE\n";
        return;
    }
    else if(l == r)
    {
        PS = 0;
        if(l % a == 0)
            PS += l;
        if(l % b == 0)
            PS += l;
    }
    else
    {
        n1 = (int)ceil(l / (float)a);
        n2 = (int)floor(r / (float)a);
        val1 = get_val(a);

        n1 = (int)ceil(l / (float)b);
        n2 = (int)floor(r / (float)b);
        val2 = get_val(b);

        PS = val1 + val2;
    }

    lcm_val = lcm(a, b);
    n1 = (int)ceil(l / (float)lcm_val);
    n2 = (int)floor(r / (float)lcm_val);
    other = get_val(lcm_val);

    cout<<PS<<" "<<other<<" "<<PS - other<<" "<<lcm_val<<"\n";

    bool flag1 = false, flag2 = false;

    if(abs(PS - other) % 2 == 0)
        flag1 = true;
    
    if((PS % 2 == 0) || (PS % 3 == 0))
        flag2 = true;
    
    if(flag1 && flag2)
        cout<<"TRUE LOVE\n";
    else if(flag1 || flag2)
        cout<<"LOVE\n";
    else
        cout<<"FAKE LOVE\n";
}

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        read();
        solve();
    }
    
    return 0;
}