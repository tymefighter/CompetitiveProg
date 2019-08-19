#include<iostream>

using namespace std;

int main()
{
    int n, ct = 1;
    while(cin>>n)
    {
        if(!n)
            break;
        printf("Case %d: %d\n", ct, n/2);
        ct++;
    }
    return 0;
}