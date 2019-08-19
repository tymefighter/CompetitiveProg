#include<iostream>

using namespace std;

int n;
int a[16];

bool check(int choice)
{
    int i, j, val = 0;
    for(i = 1, j = 0;j < n; j++, i = i << 1)
    {
        if(choice & i)
            val += a[j];
        else
            val -= a[j];
        val %= 360;
    }

    if(! val)
        return true;
    else
        return false;
}

int main()
{
    bool flag = false;
    int i;
    cin>>n;
    for(i = 0;i < n;i++)
        cin>>a[i];
    
    for(i = 1;i < (1 << n); i++)
    {
        if(check(i))
        {
            cout<<"YES\n";
            flag = true;
            break;
        }
    }

    if(! flag)
        cout<<"NO\n";
    return 0;
}