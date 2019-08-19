#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(!n)
            break;
        cout<<ceil(log2(n + 1)) - 1<<"\n";
    }
    return 0;
}