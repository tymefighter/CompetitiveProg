#include<iostream>

using namespace std;

int n;
int a[1000000];

int solve()
{
    int len, max_len = 1;

    len = 1;
    for(int i = 1;i < n;i++)
    {
        if(a[i] <= 2*a[i-1])
            len++;
        else
        {
            max_len = max(max_len, len);
            len = 1;
        }
    }

    max_len = max(max_len, len);
    return max_len;
}

int main()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>a[i];
    cout<<solve()<<'\n';
    return 0;
}