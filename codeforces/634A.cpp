#include<iostream>

using namespace std;

int n;
int a[200005], b[200005];


void read()
{
    cin>>n;
    n--;
    int i;
    for(i = 0;i < n;i++)
    {
        cin>>a[i];
        if(!a[i]) // if zero ignore it
            i--;
    }
    for(i = 0;i < n;i++)
    {
        cin>>b[i];
        if(!b[i]) // if zero ignore it
            i--;
    }
}

bool solve()
{
    int i = 0, j = 0;

    while(a[i] != 1)
        i++;
    while(b[j] != 1)
        j++;

    for(int k = 0;k < n;k++)
    {
        if(a[(i + k) % n] != b[(j + k) % n])
            return false;
    }

    return true;
}

int main()
{
    read();
    if(solve())
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}