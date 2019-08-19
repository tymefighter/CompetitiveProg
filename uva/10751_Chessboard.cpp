#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

double n, sqr2 = sqrt(2);

double solve()
{
    if(n == 0 || n == 1)
        return 0;
    else if(n == 2)
        return 4;
    
    return sqr2 * (n - 2) * (n - 2) + (n * n - (n - 2) * (n - 2));
}

double get_prec(double ans)
{
    return ((int)(ans * 1000 + 0.5)) / 1000.;
}

int main()
{
    double ans;
    int t;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        cin>>n;
        ans = solve();
        ans = get_prec(ans);
        printf("%0.3f\n", ans);
    }
    return 0;
}