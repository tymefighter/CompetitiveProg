#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100005;
int n, b, a[N];

void solve(int c)
{
    sort(a, a + n);

    long long sum_val = 0;
    int count_val = 0;
    for(int i = 0;i < n;i++)
    {
        if(sum_val + a[i] > b)
            break;
        
        sum_val += a[i];
        count_val ++;
    }

    printf("Case #%d: %d\n", c, count_val);
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        cin>>n>>b;
        for(int i = 0;i < n;i++)
            cin>>a[i];
        solve(i);
    }
    
    return 0;
}