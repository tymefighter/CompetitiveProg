#include<iostream>

using namespace std;

int n, k, m, t, l;

void read_solve()
{
    cin>>n>>k>>m>>t;
    int q, i;

    l = n;

    while(t--)
    {
        cin>>q>>i;
        if(q)
        {
            if(i <= k)
                k++;
            l++;
        }
        else
        {
            if(i < k)
            {
                k -= i;
                l -= i;
            }
            else
                l = i;
        }

        cout<<l<<" "<<k<<"\n";
    }
}

int main()
{
    read_solve();
    return 0;
}