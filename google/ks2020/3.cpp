#include<iostream>
#include<cmath>
#include<cassert>

using namespace std;

const int N = 100005;
int n, k, m[N];
int max_diff;

void read()
{
    max_diff = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &m[i]);
        if(i)
            max_diff = max(m[i] - m[i - 1], max_diff);
    }
}

bool isPossible(int diff_val)
{
    int k_val = k;

    for(int i = 1;i < n;i++)
    {
        int d = m[i] - m[i - 1];
        if(d <= diff_val)
            continue;
        
        int req = (d / diff_val) - 1;
        if(ceil(d / (double)(req + 1)) <= diff_val)
        {
            if(k_val < req)
                return false;
            
            k_val -= req;
        }
        else
        {
            req ++;
            assert(ceil(d / (double)(req + 1)) <= diff_val);

            if(k_val < req)
                return false;
            k_val -= req;
        }
    }

    return true;
}

void solve(int case_no)
{
    int low = 1, high = max_diff, mid, ans = max_diff;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(isPossible(mid))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    printf("Case #%d: %d\n", case_no, ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1;i <= t;i++)
    {
        read();
        solve(i);
    }
    return 0;
}