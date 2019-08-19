#include<iostream>

using namespace std;

long long int n, m, k;

bool simulate(long long int x)
{
    long long int used = x;

    if(x >= k)
        used += (k - 1) * x - (k * (k - 1)) / 2;
    else
        used += (x * (x - 1)) / 2 + (k - x);
    
    if(x >= n - k)
        used += (n - k) * x - ((n - k) * (n - k + 1)) / 2;
    else
        used += (x * (x - 1)) / 2 + (n - k - x + 1);

    if(used > m)
        return false;

    return true;
}

int b_search()
{
    if(n == 1 && k == 1)
        return m;

    long long int low = 1, high = m, mid;
    mid = (low + high) / 2;

    while(low <= high)
    {
        if(mid < m && simulate(mid) && !simulate(mid + 1))
            return mid;
        else if(mid < m && simulate(mid + 1))
            low = mid + 1;
        else
            high = mid - 1;
        mid = (low + high) / 2;
    }

    return -1;
}

int main()
{
    cin>>n>>m>>k;
    cout<<b_search()<<"\n";
    return 0;
}