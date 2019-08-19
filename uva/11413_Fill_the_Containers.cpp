#include<iostream>

using namespace std;

int n, m;
int a[1000];

void read()
{
    int i, j;
    for(i = 0;i < n;i++)
        cin>>a[i];
}

bool tryCapacity(long long int cap)
{
    int i = 0, n_cont = m;
    long long int x = cap;

    while(i < n)
    {
        if(a[i] > cap)
            return false;
        
        if(a[i] > x)
        {
            if(n_cont == 0)
                return false;

            x = cap;
            n_cont--;
        }
        else
        {
            if(n_cont == 0)
                return false;

            x -= a[i] * 1ll;
            i++;
        }

    }

    return true;
}

long long int b_search()
{
    long long int low = 0, high = 1000000000005*1ll, mid;

    mid = (low + high) / 2;

    while(low <= high)
    {
        if(mid > 0 && tryCapacity(mid) && !tryCapacity(mid - 1))
            return mid;
        
        if(mid > 0 && tryCapacity(mid - 1))
            high = mid - 1;
        else if(!tryCapacity(mid))
            low = mid + 1;

        mid = (low + high) / 2;
    }

    return -1;
}

int main()
{
    while(cin>>n>>m)
    {
        read();
        cout<<b_search()<<"\n";
    }

    return 0;
}