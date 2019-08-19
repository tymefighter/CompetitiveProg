#include<iostream>

using namespace std;

int n;
char a[300005];

void read()
{
    cin>>n;

    for(int i = 0;i < n;i++)
        cin>>a[i];
}

void solve()
{
    int balanced = 0;

    for(int i = 0;i < n;i++)
    {
        if(a[i] == '?')
        {
            if(balanced < 2 && i != n - 1)
            {
                a[i] = '(';
                balanced++;
            }
            else
            {
                a[i] = ')';
                balanced--;
            }
        }
        else
        {
            if(a[i] == '(')
                balanced++;
            else
                balanced--;
        }

        if(balanced <= 0 && i != n - 1)
        {
            balanced = -100;
            break;
        }
    }

    if(balanced != 0)
        cout<<":(\n";
    else
    {
        for(int i = 0;i < n;i++)
            cout<<a[i];
        cout<<"\n";
    }
}

int main()
{
    read();
    solve();
    return 0;
}
