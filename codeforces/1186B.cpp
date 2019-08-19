#include<iostream>
#include<cmath>

using namespace std;

int n, m;
long long int min_val, max_val, ans, val;

int main()
{
    cin>>n>>m;
    
    max_val = max(n, m) * 1ll;
    min_val = min(n, m) * 1ll;

    if(min_val % 3 == 2)              // rem: 2
        val = ceil((float)max_val / 2.0);
    else if(min_val % 3 == 1)         // rem: 1
        val = max_val / 3;
    else                        // rem: 0
        val = 0;

    ans = ceil((float)max_val / 2.0) * (min_val / 3) + val;
    cout<<ans<<"\n";
    return 0;
}