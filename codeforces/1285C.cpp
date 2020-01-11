#include<iostream>
#include<vector>

using namespace std;

int n;
long long Xc;
vector<long long> pf, pr;

void getPF()
{
    pf.clear();
    pr.clear();
    long long val, X = Xc;
    for(long long p = 2;p * p <= X;p ++)
    {
        if(X % p)
            continue;

        val = 1;
        while(X % p == 0)
        {
            X /= p;
            val *= p;
        }
        
        pf.push_back(val);
        pr.push_back(p);
    }

    if(X != 1)
    {
        pf.push_back(X);
        pr.push_back(X);
    }

    n = pf.size();
}

void solve()
{
    if(pf.size() == 0)
    {
        cout<<"1 1\n";
        return;
    }

    int i;
    long long ans = Xc, a = 1, b = Xc;

    for(long long p = 2;p * p <= Xc;p ++)
    {
        if(Xc % p)
            continue;

        for(i = 0;i < n;i++)
        {
            if(p % pr[i] == 0 && p % pf[i] != 0)
                break;
        }
        
        if(i == n)
        {
            if(max(p, Xc / p) < ans)
            {
                ans = max(p, Xc / p);
                a = p;
                b = Xc / p;
            }
        }
    }

    cout<<a<<" "<<b<<"\n";
}

int main()
{
    cin>>Xc;
    getPF();
    solve();

    return 0;
}