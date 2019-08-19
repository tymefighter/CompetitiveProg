#include<iostream>
#include<set>
#include<vector>
#include<map>

using namespace std;

int n;
map<int, int> m, gt_div;
vector<int> primes, a;
vector<bool> is_prime;
multiset<int> s;

int findGD(int x)
{
    for(int pr : primes)
    {
        if(!(x % pr))
            return x / pr;
    }

    return -1;
}

void pre_comp()
{
    is_prime.assign(2750132, true);
    int i, j;
    for(i = 2;i <= 2750131;i++)
    {
        if(! is_prime[i])
            continue;
        
        primes.push_back(i);
        m[i] = primes.size();
        for(j = 2;i * j <= 2750131;j++)
            is_prime[i * j] = false;
    }

    for(i = 2;i <= 2750131;i++)
    {
        if(is_prime[i])
            continue;
        gt_div[i] = findGD(i);
    }
}

void read()
{
    cin>>n;
    int x;
    for(int i = 0;i < 2 * n;i++)
    {
        cin>>x;
        s.insert(x);
    }
}

void solve()
{
    int x;
    while(!s.empty())
    {
        auto it = s.end();
        it--;
        x = *it;
        if(is_prime[x])
        {
            auto it2 = s.find(m[x]);
            a.push_back(m[x]);
            s.erase(it);
            s.erase(it2);
        }
        else
        {
            auto it2 = s.find(gt_div[x]);
            a.push_back(x);
            s.erase(it);
            s.erase(it2);
        }
    }

    for(int u : a)
        cout<<u<<" ";
    cout<<"\n";
}

int main()
{
    pre_comp();
    read();
    solve();
    return 0;
}