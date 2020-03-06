#include<iostream>
#include<cassert>

using namespace std;

const int N = 1e6+5;
int eulerPhi[N + 1];
long long epSum[N + 1]; // Euler Phi sum

void computeEulerPhi()
{
    for(int i = 1;i <= N;i++)
        eulerPhi[i] = i;
    epSum[0] = 0;
    epSum[1] = 2;

    for(int i = 2;i <= N;i++)
    {
        if(eulerPhi[i] == i)
        {
            for(int j = i;j <= N;j += i)
                eulerPhi[j] -= eulerPhi[j] / i;
        }

        epSum[i] = epSum[i - 1] + (long long) eulerPhi[i];
    }
}

int b_search(long long x)
{
    int low = 1, high = N, mid, idx = 1;
    
    assert(epSum[high] >= x);

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(epSum[mid] <= x)
        {
            idx = max(idx, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return idx;
}

int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}

long long n;

void solve()
{
    int idx = b_search(n);

    if(n > epSum[idx])
    {
        n -= epSum[idx];
        idx ++;
    }
    else
        n -= epSum[idx - 1];

    for(int i = 0;i <= idx;i++)
    {
        if(gcd(i, idx) == 1)
        {
            n --;
            if(!n)
            {
                printf("%d/%d\n", i, idx);
                return;
            }
        }
    }
}

int main()
{
    computeEulerPhi();
    while(cin>>n)
    {
        if(!n)
            break;
        solve();
    }
    return 0;
}