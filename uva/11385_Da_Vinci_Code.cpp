#include<iostream>
#include<string>
#include<sstream>
#include<map>

using namespace std;

int n, a[105];
map<int, int> fib2ind;
string s;
stringstream ss;

void generate()
{
    int f1 = 1, f2 = 2, f;
    fib2ind[1] = 0;
    fib2ind[2] = 1;

    for(int i = 2;i <= 44;i++)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        fib2ind[f] = i;
    }

}

void read()
{
    string x;
    
    getline(cin, x);
    ss.clear();
    ss.str(x);
    ss >> n;
    
    getline(cin, x);
    ss.clear();
    ss.str(x);
    for(int i = 0;i < n;i++)
        ss >> a[i];

    getline(cin, x);

    s = "";
    for(char c : x)
    {
        if('A' <= c && c <= 'Z')
            s.push_back(c);
    }
}

void solve()
{
    string ans;
    ans.assign(105, ' ');

    for(int i = 0;i < n;i++)
    {
        ans[fib2ind[a[i]]] = s[i];
    }

    while(!ans.empty() && ans[ans.size() - 1] == ' ')
        ans.pop_back();

    cout<<ans<<"\n";
}

int main()
{
    int t;
    generate();

    getline(cin, s);
    ss.clear();
    ss.str(s);
    ss >> t;

    while(t--)
    {
        read();
        solve();
    }
    return 0;
}