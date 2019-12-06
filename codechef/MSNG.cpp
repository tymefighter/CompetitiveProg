#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const long long LARGE = 1000000000000;
int n;
set<pair<long long, int> > m;

long long convertBase(int base, string s)
{
    reverse(s.begin(), s.end());
    long long val = 0, pw = 1, num;

    for(auto x : s)
    {
        if('0' <= x && x <= '9')
            num = (x - '0');
        else
            num = (x - 'A' + 10);
        
        if(num >= base)
            return -1;

        if(pw > LARGE)
            return -1;
        
        val += num * pw;

        if(val > LARGE)
            return -1;

        pw = pw * base;
    }

    if(val > LARGE)
        return -1;

    return val;
}

void read_solve()
{
    cin>>n;
    int i, j, base;
    long long val;
    string s;

    m.clear();

    for(i = 0;i < n;i++)
    {
        cin>>base>>s;
        if(base != -1)
        {
            val = convertBase(base, s);
            if(val != -1)
                m.insert({val, i});
            
            continue;
        }

        for(j = 2;j <= 36;j++)
        {
            val = convertBase(j, s);
            if(val != -1)
                m.insert({val, i});
        }
    }

    long long int prev = -1;
    int ct = 0;

    for(auto x : m)
    {
        if(x.first == prev)
            ct ++;
        else
        {
            prev = x.first;
            ct = 1;
        }

        if(ct == n)
        {
            cout<<x.first<<"\n";
            return;
        }
    }

    cout<<"-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
        read_solve();
    return 0;
}