#include<iostream>
#include<deque>

using namespace std;

deque<int> dq;

int n, k;
int a[100005];

void read()
{
    cin>>n>>k;
    for(int i = 0;i < n;i++)
        cin>>a[i];
}

void solve()
{
    int i;
    for(i = 0;i < k;i++)
    {
        while(!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();

        dq.push_back(i);
    }

    cout<<a[dq.front()]<<"\n";
    for(;i < n;i++)
    {
        while(dq.front() <= i - k)
            dq.pop_front();
        
        while(!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();
        
        dq.push_back(i);
        cout<<a[dq.front()]<<"\n";
    }
}

int main()
{
    read();
    solve();
    return 0;
}