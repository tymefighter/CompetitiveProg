#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

string findMax(int m, int s, bool fmin)
{
    int x, i, actual = s;
    bool found = false;
    string ans;
    for(x = 9;x >= 0;x--)
    {
        if(!fmin && x == 0)
            break;

        ans.clear();
        ans.push_back((char)x + '0');
        s = actual - x;
        i = m - 1;
        //cout<<s<<"--\n";
        while(s >= 0 && i > 0 && x >= 0)
        {
            if(s - x < 0)
                x--;
            else
            {
                s -= x;
                ans.push_back((char)x + '0');
                i--;
            }
        }
        if(s == 0 && i == 0)
        {
            found = true;
            break;
        }
    }

    if(found)
        return ans;
    else
        return "";
}

void solve(int m, int s)
{
    if(s == 0)
    {
        if(m == 1)
            cout<<0<<" "<<0<<"\n";
        else
            cout<<-1<<" "<<-1<<"\n";
        return;
    }
    string s1, s2;
    s1 = findMax(m, s, false);
    
    if(s1.empty())
    {
        cout<<-1<<" "<<-1<<"\n";
        return;
    }

    if(s1[s1.size()-1] == '0')
    {
        s2 = findMax(m-1, s-1, true);
        s2.push_back('1');
    }
    else
        s2 = s1;
    
    reverse(s2.begin(), s2.end());
    cout<<s2<<" "<<s1<<"\n";
}

int main()
{
    int m, s;
    
    cin>>m>>s;
    solve(m, s);
    return 0;
}