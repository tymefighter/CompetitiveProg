#include<iostream>

using namespace std;

string s;
int sa, sb;

bool solve()
{
    int d = 0;

    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == 'A')
           d = i;
        else if(s[i] == 'B')
        {
            d = i - d;
            break;
        }
    }

    return (d % (sa + sb)) == 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        cin>>sa>>sb;
        if(solve())
            cout<<"unsafe\n";
        else
            cout<<"safe\n";
    }
    return 0;
}