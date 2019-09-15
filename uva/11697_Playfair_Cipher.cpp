#include<iostream>
#include<set>
#include<sstream>
#include<map>

using namespace std;

char a[5][5];
string msg, s;
set<int> seen;
map<char, pair<int, int> > m;

void reset()
{
    seen.clear();
    seen.insert('q');
    msg.clear();
    m.clear();
}


void read()
{
    reset();
    getline(cin, s);
    int i = 0, j = 0;

    for(char x : s)
    {
        if('a' <= x && x <= 'z' && seen.find(x) == seen.end())
        {
            seen.insert(x);
            a[i][j] = x;
            j ++;
            if(j == 5)
            {
                i ++;
                j = 0;
            }
        }
    }

    for(char x = 'a';x <= 'z';x ++)
    {
        if(seen.find(x) == seen.end())
        {
            seen.insert(x);
            a[i][j] = x;
            j ++;
            if(j == 5)
            {
                i ++;
                j = 0;
            }
        }
    }
    
    getline(cin, s);
    for(char x : s)
    {
        if('a' <= x && x <= 'z')
            msg.push_back(x);
    }
}

void get_alpha_loc()
{
    int i, j;
    for(i = 0;i < 5;i++)
    {
        for(j = 0;j < 5;j++)
            m[a[i][j]] = {i, j};
    }
}

void convert_msg()
{
    s = "";
    int i = 1;
    s.push_back(msg[0]);

    while(i < msg.size())
    {
        if(msg[i - 1] == msg[i])
        {
            s.push_back('x');
            s.push_back(msg[i]);
            i ++;
        }
        else
        {
            s.push_back(msg[i]);
            if(i + 1 < msg.size())
                s.push_back(msg[i + 1]);
            i += 2;
        }
    }

    if(s.size() % 2)
        s.push_back('x');

}

void solve()
{
    int i;
    pair<int, int> a1, a2;
    string ans;
    for(i = 0;i < s.size();i += 2)
    {
        a1 = m[s[i]];
        a2 = m[s[i + 1]];

        if(a1.first == a2.first)        // Same row
        {
            ans.push_back(a[a1.first][(a1.second + 1) % 5]);
            ans.push_back(a[a2.first][(a2.second + 1) % 5]);
        }
        else if(a1.second == a2.second) // Same column
        {
            ans.push_back(a[(a1.first + 1) % 5][a1.second]);
            ans.push_back(a[(a2.first + 1) % 5][a2.second]);
        }
        else                            // Neither same column nor row
        {
            ans.push_back(a[a1.first][a2.second]);  // swap columns
            ans.push_back(a[a2.first][a1.second]);
        }
    }

    for(int i = 0;i < ans.size();i++)
        ans[i] = (ans[i] - 'a') + 'A';
    cout<<ans<<"\n";
}

int main()
{
    int t;
    stringstream ss;
    
    getline(cin, s);
    ss.str(s);
    ss >> t;

    while(t--)
    {
        read();
        get_alpha_loc();
        convert_msg();
        solve();
    }


    return 0;
}