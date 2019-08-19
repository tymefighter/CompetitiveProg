#include<iostream>
#include<cstdio>

using namespace std;

int n, k;
int a[200005];

void read_solve()
{
    cin>>n>>k;
    double val = 0, ans = 0;

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        if(i < k)
            val += (double)a[i];
        else
        {
            ans += val;
            val -= a[i - k];
            val += a[i];
        }
    }
    ans += val;

    ans /= (double) (n - k + 1);
    printf("%0.10lf\n", ans);
}

int main()
{
    read_solve();
    return 0;
}