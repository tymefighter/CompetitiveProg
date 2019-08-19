#include<iostream>
#include<string>

using namespace std;

int n;
string s;

bool solve()
{
    int i, j;

    for(i = 1;i < n;i++)
    {
        if(s[i - 1] == 'A' && s[i] == 'B')
        {
            for(j = i + 2;j < n;j++)
            {
                if(s[j - 1] == 'B' && s[j] == 'A')
                    return true;
            }
            break;
        }
    }

    for(i = 1;i < n;i++)
    {
        if(s[i - 1] == 'B' && s[i] == 'A')
        {
            for(j = i + 2;j < n;j++)
            {
                if(s[j - 1] == 'A' && s[j] == 'B')
                    return true;
            }
            break;
        }
    }

    return false;
}

int main()
{
    cin>>s;
    n = s.size();
    if(solve())
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}