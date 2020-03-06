#include<iostream>
#include<cassert>

using namespace std;

const int N = 100005;
int n, q, ct[N];

void read()
{
    ct[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        long long x;
        scanf("%lld",&x);

        ct[i] = ct[i - 1];

        if(x == 3 || x == 4 || x == 6)
            ct[i] ++;
    }
}

void solve()
{
    while(q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        assert(l <= r);
        printf("%d\n",ct[r] - ct[l - 1]);;
    }
}

int main()
{
    scanf("%d %d",&n, &q);
    read();
    solve();
    return 0;
}