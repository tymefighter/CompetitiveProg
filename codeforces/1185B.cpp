#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

string x, y;
vector<pair<char, int> > a, b;

bool solve()
{
    a.clear();
    b.clear();

    int i, val = 1;
    for(i = 1;i < x.size();i++)
    {
        if(x[i] == x[i-1])
            val++;
        else
        {
            a.push_back({x[i-1], val});
            val = 1;
        }
    }
    a.push_back({x[i-1], val});

    val = 1;
    for(i = 1;i < y.size();i++)
    {
        if(y[i] == y[i-1])
            val++;
        else
        {
            b.push_back({y[i-1], val});
            val = 1;
        }
    }
    b.push_back({y[i-1], val});

    if(a.size() != b.size())
        return false;

    for(i = 0;i < a.size();i++)
    {
        if(b[i].first != a[i].first)
            return false;
        
        if(b[i].second < a[i].second)
            return false;
    }

    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(solve())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}