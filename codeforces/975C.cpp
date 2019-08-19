#include<iostream>

using namespace std;

int n, q;
long long int ac[200005], k[200005]; // cumulative

void read()
{
    cin>>n>>q;
    int i;
    for(i = 0;i < n;i++)
    {
        cin>>ac[i];
        ac[i] += (i > 0 ? ac[i-1] : 0);
    }

    for(i = 0;i < q;i++)
        cin>>k[i];

}

int b_search(int low, long long int val)
{
    int high = n - 1, mid;
    int init_val = low;
    mid = (low + high) / 2;

    while(low <= high)
    {
        if(mid < n - 1 && ac[mid] <= val && val < ac[mid + 1])
            return mid;
        else if(mid < n - 1 && ac[mid + 1] <= val)
            low = mid + 1;
        else
            high = mid - 1;

        mid = (low + high) / 2;
    }

    return init_val;
}

void solve()
{
    int i, low = -1;
    long long int val = 0;
    for(i = 0;i < q;i++)
    {
        if(val + k[i] >= ac[n - 1])
        {
            low = -1;
            val = 0;
        }
        else
        {
            val += k[i];
            low = b_search(low, val);
        }

        cout<<(n - 1) - low<<"\n";
    }
}

int main()
{
    read();
    solve();
    return 0;
}