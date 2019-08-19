#include<iostream>
#include<cmath>

using namespace std;

int n, n_pres;
char a[1005];

void read()
{
    cin>>n;
    n_pres = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        if(a[i] == 'P')
            n_pres++;
    }
}

int solve()
{
    int pos = 0; // possible
    for(int i = 2;i < n - 2;i++)
    {
        if((a[i - 1] == 'P' || a[i - 2] == 'P') && (a[i + 1] == 'P' || a[i + 2] == 'P') && a[i] != 'P')
            pos ++;
    }

    int required = (int)ceil(0.75 * (float)n);

    if(n_pres + pos < required)
        return -1;
    
    return max(required - n_pres, 0);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        cout<<solve()<<"\n";
    }
    return 0;
}