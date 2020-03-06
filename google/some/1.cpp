#include<iostream>
#include<cstdio>

using namespace std;

int n, q, odd, even;
bool a[100005];

bool check(int x)
{
    int num = 0;
    for(int i = 1;i <= x;i = (i << 1))
    {
        if(i & x)
            num++;
    }

    if(num % 2)                 // odd
        return false;
    else                        // even
        return true;
}

void read()
{
    int x;

    odd = even = 0;

    cin>>n>>q;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(!check(x))           // odd
        {
            a[i] = true;
            odd++;
        }
        else                    // even
        {
            a[i] = false;
            even++;
        }
    }
}

void solve()
{
    int idx, x, val, j;

    for(int i = 0;i < q;i++)
    {
        if(i)
            cout<<" ";
        cin>>idx>>x;
        if(a[idx])
            odd--;
        else
            even--;

        if(!check(x))
        {
            a[idx] = true;
            odd++;
        }
        else
        {
            a[idx] = false;
            even++;
        }

        val = even;
        if(odd % 2)
        {
            val = 0;
            for(j = 0;j < n;j++)
            {
                if(a[j])
                    break;
            }

            val = n - j - 1;

            for(j = n - 1;j >= 0;j--)
            {
                if(a[j])
                    break;
            }

            val = max(max(val, j), 0);
        }
        else
            val += odd;
        cout<<val;
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        if(i != 1)
            cout<<"\n";
        printf("Case #%d: ", i);
        read();
        solve();
    }
    return 0;
}