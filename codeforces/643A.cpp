#include<iostream>

using namespace std;

int n;
int freq[5005];
int ct[5005];
int a[5005];

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>a[i];
    for(int i = 1;i <= n;i++)
        ct[i] = 0;
}

void solve()
{
    int i, j, k;
    for(i = 0;i < n;i++)
    {
        for(j = i;j < n;j++)
            freq[a[j]] = 0;

        k = a[i];
        for(j = i;j < n;j++)
        {
            freq[a[j]]++;
            if((freq[k] < freq[a[j]]) || (freq[k] <= freq[a[j]] && a[j] < k))
                k = a[j];
            ct[k]++;
        }
    }

    for(k = 1;k <= n;k++)
        cout<<ct[k]<<" ";
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}