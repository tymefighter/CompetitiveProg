#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[100005], b[100005];

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>a[i];

    sort(a, a + n);
}

bool solve()
{

    b[0] = a[0];
    int j = 1;
    bool flag = true;
    for(int i = 1;i < n;i++)
    {
        if(flag)
            b[j] = a[i];
        else
        {
            b[n - j] = a[i];
            j++;
        }
        flag = !flag;
    }


    for(int i = 0;i < n;i++)
    {
        if(b[(i + n - 1) % n] + b[(i + 1) % n] <= b[i])
            return false;
    }

    cout<<"YES\n";
    for(int i = 0;i < n;i++)
        cout<<b[i]<<" ";
    cout<<"\n";

    return true;
}

int main()
{
    read();
    if(!solve())
        cout<<"NO\n";
    return 0;
}