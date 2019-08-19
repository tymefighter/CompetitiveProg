#include<iostream>
#include<cmath>

using namespace std;

float d, v, u;

float solve()
{
    if(v >= u || v == 0)
        return -1;
    
    float t1 = d / u;
    float t2 = d / sqrt(u * u - v * v);
    
    return t2 - t1;
}

int main()
{
    int t;
    cin>>t;
    float ans;
    for(int i = 1;i <= t;i++)
    {
        cin>>d>>v>>u;

        ans = solve();
        if(ans < 0)
            printf("Case %d: can't determine\n", i);
        else
            printf("Case %d: %0.3f\n", i, ans);
    }
    return 0;
}