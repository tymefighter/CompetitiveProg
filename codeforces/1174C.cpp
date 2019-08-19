#include<iostream>

using namespace std;

int n;
int a[100009];
bool flag[100009];

// similar toSeive of Eratothesis algo

void solve()
{
    int i, j, val = 1;
    for(i = 2;i <= n;i++)
        flag[i] = false;
    
    for(i = 2;i <= n;i++)
    {
        if(flag[i])
            continue;
        for(j = 1;i * j <= n;j++)
        {
            if(flag[i*j])
                continue;
            
            a[i * j] = val;
            flag[i * j] = true;
        }
        val++;
    }

    for(i = 2;i <= n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    cin>>n;
    solve();
    return 0;
}