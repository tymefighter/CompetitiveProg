#include<iostream>
#include<vector>

using namespace std;

long long int n, k, x;
vector<long long int> a, b;

void read()
{
    a.clear();
    b.clear();
    
    cin>>n>>k;

    long long int sum = 0;
    bool used = false;;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(x % 2 == 0)
        {
            sum += x;
            used = true;
        }
        else
        {
            b.push_back(i + 1);
            a.push_back(sum + x);
            sum = 0;
            used = false;
        }
    }

    if(used && a.size() > 0)
    {
        a[a.size() - 1] += sum;
        b[b.size() - 1] = n;
    }
}

void solve()
{
    if(a.size() == 0)
    {
        cout<<"NO\n";
        return;
    }

    if(a.size() >= k && (a.size() - k) % 2 == 0)
    {
        cout<<"YES\n";

        // {
        //     for(int x : b)
        //         cout<<x<<" ";
        //     cout<<"\n";
        // }
        // else
        // {
        long long int i = a.size() - k;
        for(;i < b.size();i++)
            cout<<b[i]<<" ";
        cout<<"\n";
        //}
    }
    else
        cout<<"NO\n";
}

int main()
{
    int q;
    cin>>q;

    while(q--)
    {
        read();
        solve();
    }
    return 0;
}