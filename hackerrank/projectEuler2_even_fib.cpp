#include<iostream>
#include<vector>

using namespace std;

const long long MAX = 40000000000000000;
long long f[100], evenSum[100];
int n;

void generate()
{
    f[0] = 1, f[1] = 2;
    evenSum[0] = 0, evenSum[1] = 2;
    int i = 2;

    while(true)
    {
        f[i] = f[i - 1] + f[i - 2];
        evenSum[i] = evenSum[i - 1];

        if(!(f[i] & 1))
            evenSum[i] += f[i];

        if(f[i] > MAX)
            break;
        i ++;
    }

    n = i + 1;
}

int b_search(long long val)
{
    int low = 0, high = n - 1, mid;

    if(val >= f[n - 1])
        return n - 1;

    if(val < f[0])
        return -1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(mid < n - 1 && f[mid] <= val && f[mid + 1] > val)
            return mid;
        else if(mid < n - 1 && f[mid + 1] <= val)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void solve()
{
    long long val;
    cin>>val;
    int idx = b_search(val);

    if(idx == -1)
        cout<<0<<"\n";
    else
        cout<<evenSum[idx]<<"\n";
}

int main()
{
    generate();
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}