#include<iostream>
#define MAX 100000000

using namespace std;

long long int c_h[200005];
int min_ht, max_ht;
int n, k;

void reset()
{
    for(int i = 0;i < 200005;i++)
        c_h[i] = 0;
}

void read()
{
    cin>>n>>k;
    int h;
    
    min_ht = MAX;
    max_ht = -1;

    for(int i = 0;i < n;i++)
    {
        cin>>h;
        c_h[h] += 1ll;
        min_ht = min(min_ht, h);
        max_ht = max(max_ht, h);
    }
}

void solve()
{
    int h;
    for(h = max_ht - 1;h >= 0;h--)
        c_h[h] += c_h[h + 1];

    for(h = max_ht - 1;h >= 0;h--)
        c_h[h] += c_h[h + 1];

    int start = max_ht;
    int ans = 0;



    for(h = max_ht;h > min_ht;h--)
    {
        if(c_h[h - 1] - c_h[start + 1] > (k * 1ll))
        {
            start = h - 1;
            ans++;
        }
    }

    if(start != min_ht)
        ans++;

    cout<<ans<<"\n";
}

int main()
{
    reset();
    read();
    solve();
    return 0;
}