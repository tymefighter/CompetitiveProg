#include<iostream>
#include<set>
#include<string>
#include<sstream>

using namespace std;

stringstream ss;
string s;
set<string> dt;

void read()
{
    string a;
    while(getline(cin, a))
    {
        if(a == "#")
            break;
        dt.insert(a);
    }

    getline(cin, s);
}

void increase()
{
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == 'Z')
            s[i] = ' ';
        else if(s[i] == ' ')
            s[i] = 'A';
        else
            s[i] = s[i] + 1;
    }
}

int get_count()
{
    int ct = 0;
    ss.clear();
    ss.str(s);
    string a;

    while(!ss.eof())
    {
        ss >> a;
        if(dt.find(a) != dt.end())
            ct ++;
    }

    return ct;
}

void get_ans(int k)
{
    int val;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == ' ')
            val = k;
        else
            val = (s[i] - 'A' + 1 + k) % 27;
        if(val == 0)
            s[i] = ' ';
        else
            s[i] = (val - 1) + 'A';
    }

    int line_ct = 0;

    while(!s.empty() && s[s.size() - 1] == ' ')
        s.pop_back();

    ss.clear();
    ss.str(s);

    while(!ss.eof())
    {
        ss >> s;
        if(line_ct + s.size() <= 60)
        {
            if(line_ct != 0)
            {
                line_ct += s.size() + 1;
                cout<<" "<<s;
            }
            else
            {
                line_ct += s.size();
                cout<<s;
            }
            
        }
        else
        {
            line_ct = s.size();
            cout<<"\n"<<s;
        }
    }
    cout<<"\n";
}

void solve()
{
    int k, ct, best_count = 0, best_k = 0;

    for(k = 0;k < 27;k++)
    {
        ct = get_count();
        if(ct > best_count)
        {
            best_count = ct;
            best_k = k;
        }
        increase();
    }

    get_ans(best_k);
}

int main()
{
    read();
    solve();
    return 0;
}