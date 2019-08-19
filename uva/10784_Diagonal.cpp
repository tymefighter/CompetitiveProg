#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int ct = 1;
    long long int n, ans;
    while(cin>>n)
    {
        if(!n)
            break;
        
        ans = (int)ceil((3. + sqrt(9. + 8. * n)) / 2.);
        printf("Case %d: %lld\n", ct, ans);
        ct++;
    }
    return 0;
}