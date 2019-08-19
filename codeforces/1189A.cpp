#include<iostream>


using namespace std;

int n;
int nz, no;
char a[105];

void read()
{
    cin>>n;
    no = nz = 0;

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        if(a[i] == '0')
            nz++;
        else
            no++;
    }
}

void solve()
{
    if(no == nz)
    {
        cout<<"2\n";
        for(int i = 0;i < n - 1;i++)
            cout<<a[i];
        cout<<" "<<a[n - 1]<<"\n";
    }
    else
    {
        cout<<"1\n";
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