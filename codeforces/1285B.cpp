#include<iostream>

using namespace std;

const int N = 100005;
int n;
long long a[N], total_sum;

void read()
{
    total_sum = 0;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        total_sum += a[i];
    }
}

bool solve()
{
    int opt_l = 0, opt_r = 0, prev_inc = 0;
    long long opt_sum = a[0], sm = 0;

    for(int i = 0;i < n;i++)
    {
        sm += a[i];

        if(sm > opt_sum)
        {
            opt_sum = sm;
            opt_l = prev_inc;
            opt_r = i;
        }


        if(sm <= 0)
        {
            sm = 0;
            prev_inc = i + 1;
        }
    }

    if(opt_sum > total_sum)
        return false;
    else if(opt_sum == total_sum && (opt_r - opt_l + 1) < n)
        return false;
    else
        return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        if(solve())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}