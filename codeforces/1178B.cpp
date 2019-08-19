#include<iostream>
#include<string>

using namespace std;

void solve()
{
    string s, a;
    cin>>s;
    int no_v = 0, i;

    a.clear();
    for(char x : s)
    {
        if(x == 'v')
            no_v++;
        else
        {
            for(i = 0;i < no_v - 1;i++)
                a.push_back('w');
            a.push_back(x);
            no_v = 0;
        }
    }

    for(i = 0;i < no_v - 1;i++)
        a.push_back('w');

    
    long long int w = 0, wo = 0, wow = 0;
    
    for(char x : a)
    {
        if(x == 'w')
        {
            wow += wo;
            w++;
        }
        else if(x == 'o')
            wo += w;
    }

    cout<<wow<<"\n";
}

int main()
{
    solve();
    return 0;
}