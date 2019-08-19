#include<iostream>
#define VAL 1000000007

using namespace std;


long long int pow(int n)
{

    if(n == 0)
        return 1;
    
    long long int val;
    if(n % 2)
        val = ((pow(n - 1) % VAL) * (2ll)) % VAL;
    else
    {
        long long int val1 = pow(n / 2) % VAL;
        val = (val1 * val1) % VAL;
    }
        
    return val;
}

int main()
{
    int t;
    int k;
    cin>>t;

    while(t--)
    {
        cin>>k;
        cout<<((5l * ((pow(k) - 2l) % VAL)) % VAL + 10l) % VAL<<"\n";
    }
    return 0;
} 