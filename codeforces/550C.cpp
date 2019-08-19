#include<iostream>
#include<string>

using namespace std;

int n;
string s;

void solve()
{
    int i, j, k;
    int b2, b1, b0;

    for(i = 0;i < n;i++)
    {
        b2 = s[i] - '0';
        for(j = i + 1;j < n;j++)
        {
            if(b2 == 0)
                break;

            b1 = s[j] - '0';
            for(k = j + 1;k < n;k++)
            {
                if(b1 == 0)
                    break;

                b0 = s[k] - '0';
                if((4 * (b2 % 8) + 2 * (b1 % 8) + (b0 % 8)) % 8 == 0)
                {
                    cout<<"YES\n";
                    cout<<s[i]<<s[j]<<s[k]<<"\n";
                    return;
                }
            }
            if((2 * (b2 % 8) + (b1 % 8)) % 8 == 0)
            {
                cout<<"YES\n";
                cout<<s[i]<<s[j]<<"\n";
                return;
            }
        }
        if(b2 % 8 == 0)
        {
            cout<<"YES\n";
            cout<<s[i]<<"\n";
            return;
        }
    }

    cout<<"NO\n";
}

int main()
{
    cin>>s;
    n = s.size();
    solve();
    return 0;
}