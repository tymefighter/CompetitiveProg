#include<iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    if(k >= n && m >= n)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}