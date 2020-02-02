#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> pf, ct;

void solve()
{
    pf.clear();
    ct.clear();

    int actual_n = n, t_count = 0;

    for(int i = 2;i * i <= n;i++)
    {
        if(n % i == 0)
        {
            pf.push_back(i);
            ct.push_back(0);
            while(n % i == 0)
            {
                n /= i;
                ct[ct.size() - 1] ++;
            }

            t_count += ct[ct.size() - 1];
        }
    }

    if(n != 1)
    {
        pf.push_back(n);
        ct.push_back(1);
        t_count ++;
    }

    if(pf.size() >= 3)
    {
        cout<<"YES\n";
        cout<<pf[0]<<" "<<pf[1]<<" "<<(actual_n / pf[0]) / pf[1]<<"\n";
    }
    else if(pf.size() == 2)
    {
        if(t_count < 4)
        {
            cout<<"NO\n";
            return;
        }

        cout<<"YES\n";
        cout<<pf[0]<<" "<<pf[1]<<" "<<(actual_n / pf[0]) / pf[1]<<"\n";
    }
    else if(pf.size() == 1)
    {
        if(t_count < 6)
        {
            cout<<"NO\n";
            return;
        }

        cout<<"YES\n";
        cout<<pf[0]<<" "<<pf[0] * pf[0]<<" "<<((actual_n / pf[0]) / pf[0]) / pf[0]<<"\n";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        solve();
    }
    return 0;
}