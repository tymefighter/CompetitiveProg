#include<iostream>
#include<algorithm>

using namespace std;

string s, ans;

char convert()
{
    reverse(s.begin(), s.end());
    int val = 0, pw = 1;

    for(char x : s)
    {
        if(x == 'o')
        {
            val += pw;
            pw *= 2;
        }
        else if(x == ' ')
            pw *= 2;
    }

    return (char)val;
}

void read_solve()
{
    getline(cin, s);
    while(getline(cin, s))
    {
        if(s == "___________")
            break;
        ans.push_back(convert());
    }

    cout<<ans;
}

int main()
{
    read_solve();
    return 0;
}