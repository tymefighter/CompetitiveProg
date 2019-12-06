#include<iostream>

using namespace std;

int num1, num2;

void read()
{
    int n, x;
    cin>>n;

    num1 = num2 = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(x == 1)
            num1 ++;
        else
            num2 ++;
    }
}

void solve()
{
    if(num1 == 0 || num2 == 0)
    {
        while(num1 --)
            cout<<"1 ";
        
        while(num2 --)
            cout<<"2 ";
    }
    else
    {
        cout<<"2 1 ";
        num1 --, num2 --;

        while(num2 --)
            cout<<"2 ";
        while(num1 --)
            cout<<"1 ";
    }

    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}