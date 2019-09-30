#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long int n;
string s;     // fact: factorial - base representation of n
vector<int> fact;

void getFactRep()
{
    fact.clear();
    int i = 1;
    while(n)
    {
        fact.push_back(n % i);
        n /= i;
        i ++;
    }

    while(fact.size() < s.size())
        fact.push_back(0);

    reverse(fact.begin(), fact.end());
}

void solve()
{
    sort(s.begin(), s.end());
    string ans;

    for(int f : fact)
    {
        ans.push_back(s[f]);
        s.erase(f, 1);
    }

    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        cin>>n;
        getFactRep();
        solve();
    }
    return 0;
}

