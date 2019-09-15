#include<iostream>

using namespace std;

int n[3];
string s;

bool solve()
{
    int i = 0;
    n[0] = n[1] = n[2] = 0;

    for(char x : s)
    {
        if(x == 'M' || x == 'E')
        {
            i ++;
            if(i > 2)
                return false;
            continue;
        }
        else if(x == '?')
            n[i] ++;
        else
            return false;
    }

    if(n[0] >= 1 && n[1] >= 1 && n[0] + n[1] == n[2])
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin>>t;
    getline(cin, s);
    while(t--)
    {
        getline(cin, s);
        if(solve())
            cout<<"theorem\n";
        else
            cout<<"no-theorem\n";
    }
    return 0;
}