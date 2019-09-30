#include<iostream>

using namespace std;

string s;

void solve()
{
    int l = s.size(), n;
    string u, v, w;

    for(n = (l / 3) + 1;n <= (l / 2);n++)
    {
        u = s.substr(0, n);
        v = s.substr(n, n);
        w = s.substr(2 * n);

        if(u == v && u.substr(0, w.size()) == w)
            break;
    }

    int i = w.size();

    for(int j = 0;j < 8;j++)
    {
        cout<<u[i];
        i = (i + 1) % u.size();
    }
    cout<<"...\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        solve();
    }
    return 0;
}