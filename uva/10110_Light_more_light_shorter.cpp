#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long long int n, sqrn;
    while(cin>>n)
    {
        if(!n)
            break;
        sqrn = (long long int)sqrt(n);
        if(n == sqrn * sqrn)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    
    return 0;
}