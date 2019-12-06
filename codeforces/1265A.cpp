#include<iostream>

using namespace std;

string s;

bool checkStr()
{
    for(int i = 0;i < s.size() - 1;i++)
    {
        if(s[i] == s[i + 1] && s[i] != '?')
            return false;
    }
    return true;
}

bool used[3];

void solve()
{
    if(!checkStr())
    {
        cout<<"-1\n";
        return;
    }

    int i, j;
    for(i = 0;i < s.size();i++)
    {
        if(s[i] == '?')
        {

            for(j = 0;j < 3;j++)
                used[j] = false;

            if(i - 1 >= 0)
                used[s[i - 1] - 'a'] = true;
            if(i + 1 < s.size() && s[i + 1] != '?')
                used[s[i + 1] - 'a'] = true;

            for(j = 0;j < 3;j++)
            {
                if(!used[j])
                {
                    s[i] = 'a' + j;
                    break;
                }
            }
        }
    }

    cout<<s<<"\n";
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