#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    cout<<((n-1) * (n) * (2*n - 1)) / 6 + ((n - 1) * (n)) / 2 - 2<<'\n';
    return 0;
}