#include<iostream>

using namespace std;


/*
    This code is not complete,

    Pls complete it !!!
*/

int l, n;
int c[51];

void read()
{
    cin>>n;

    for(int i = 0;i < n;i++)
        cin>>c[i];
}

int main()
{
    while(cin>>l)
    {
        if(!l)
            break;
        read();
    }

    return 0;
}