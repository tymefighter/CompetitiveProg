#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
long long int d;
long long int in[1005], a[1005];
long long int ct[1005]; // count
long long int mean, tsum;


void read()
{
    cin>>n>>d;

    tsum = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>in[i];
        tsum += in[i];
    }
    mean = tsum / (n * 1ll);
}

void process()
{
    sort(in, in + n);
    int i;
    ct[0] = 1;
    a[0] = in[0];
    m = 0;
    for(i = 1;i < n;i++)
    {
        if(in[i] == in[i-1])
            ct[m] ++;
        else    
        {
            //cout<<i<<" "<<in[i]<<"--\n";
            m++;
            a[m] = in[i];
            ct[m] = 1;
        }
    }
    m++;

    /*for(i = 0;i < m;i++)
        cout<<a[i]<<" ";
    cout<<"----A\n";
    for(i = 0;i < m;i++)
        cout<<ct[i]<<" ";
    cout<<"----A\n";*/
}

void solve()
{
    int i;
    long long int val = 0;
    for(i = 0;i < n;i++)
        val += abs(in[i] - mean);
    val /= 2ll;

    if(d >= val)
    {
        if(tsum % (n * 1ll) == 0)
            cout<<"0\n";
        else
            cout<<"1\n";
        return;
    }

    process();

    long long int min_val, max_val;
    long long int cum_ct = ct[0];
    long long int dt = d;
    for(i = 0;i <= m - 2;i++)
    {
        val = (a[i + 1] - a[i]) * cum_ct;
        if(val > dt)
        {
            min_val = a[i] + (dt / cum_ct);
            break;
        }
        else
            dt -= val;

        cum_ct += ct[i + 1];
    }

    cum_ct = ct[m - 1];
    dt = d;
    for(i = m - 1;i >= 1;i--)
    {
        val = (a[i] - a[i - 1]) * cum_ct;
        if(val > dt)
        {
            //cout<<i<<" "<<a[i]<<" "<<dt<<" "<<cum_ct<<" "<<val<<"\n";
            max_val = a[i] - (dt / cum_ct);
            break;
        }
        else
            dt -= val;

        cum_ct += ct[i - 1];
    }

    //cout<<max_val<<" "<<min_val<<"--\n";
    cout<<max_val - min_val<<"\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        solve();
    }
    return 0;
}