#include<iostream>
#include<map>

using namespace std;

int n;
map<long long int, int> m;

void reset()
{
    m.clear();
}

void read()
{
    cin>>n;
    long long int x;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        m[x] ++;
    }
}

void solve()
{
    bool flag = true;
    pair<long long int, int> val;
    long long int a;
    int c;

    long long int ch = 0, ha = 0;

    for(auto it = m.rbegin(); it != m.rend(); it++)
    {
        val = *it;
        a = val.first, c = val.second;
        //cout<<a<<" |--| "<<c<<" f: "<<flag<<"\n";
        if(c == 1)
        {
            if(flag)
                ch += a;
            else
                ha += a;

            flag = !flag;

            m[a/2] ++;
        }
        else if(c > 1)
            flag = !flag;
    }

    //cout<<ch<<" "<<ha<<"\n";

    if(ch > ha)
        cout<<"Cherry "<<ch-ha<<"\n";
    else
        cout<<"Hazardous\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        reset();
        read();
        solve();
    }

    return 0;
}