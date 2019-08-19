#include<iostream>
#include<string>
#include<vector>

using namespace std;

int n, m, no;
string s;
int c[26];
vector<vector<int> > a(26);

void reset_c()
{
    for(int i = 0;i < 26;i++)
        c[i] = 0;
}

void read()
{
    cin>>n;
    cin>>s;

    for(int i = 0;i < s.size();i++)
        a[s[i] - 'a'].push_back(i);
}

void read_str()
{
    cin>>s;
    no = s.size();

    reset_c();
    for(char x : s)
        c[x - 'a'] ++;
}


void solve_util()
{
    int ans = -1, val;

    for(int i = 0;i < 26;i++)
    {
        if(!c[i])
            continue;

        ans = max(ans, a[i][c[i] - 1] + 1);
    }

    cout<<ans<<"\n";
}

void solve()
{
    cin>>m;
    while(m--)
    {
        read_str();
        solve_util();
    }
}

int main()
{
    read();
    solve();
    return 0;
}