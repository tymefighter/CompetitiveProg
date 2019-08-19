#include<iostream>

using namespace std;

int n;
int a[11];

bool checkAns()
{
    int x = -1, y = -1, i = 1;

    while(i < 11 && a[i] == 0)
        i++;
    
    x = a[i];
    i++;

    int num_x = 0;
    while(i < 11 && (a[i] == 0 || a[i] == x))
    {
        num_x += (a[i] == x ? 1 : 0);
        i++;
    }
    
    if(i == 11)
    {
        if(num_x == 0 || x == 1)  // only a single number came up or x was 1 (so we may remove it)
            return true;
        else
            return false;
    }
    
    y = a[i];
    i++;

    while(i < 11 && (a[i] == 0 || a[i] == x || a[i] == y))
        i++;

    if(i != 11)
        return false;

    if(abs(y - x) != 1 && (x != 1 && y != 1)) // one of them has to be one greater, or one of them has to be 1
        return false;

    int num_min, mn, num_max, mx;
    num_max = num_min = 0;
    mn = min(x, y);
    mx = max(x, y);


    for(i = 1;i <= 10;i++)
    {
        if(a[i] == mn)
            num_min++;
        else if(a[i] == mx)
            num_max++;
    }


    if((num_min == 1 && mn == 1) || (abs(mx - mn) == 1 && num_max == 1))
        return true;
    else
        return false;
}

void solve()
{
    int i, x, ans;
    for(i = 0;i < 11;i++)
        a[i] = 0;
    

    cin>>n;
    for(i = 1;i <= n;i++)
    {
        cin>>x;
        a[x] += 1;
        if(i < 2)
            ans = i;
        else if(checkAns())
        {
            //cout<<i<<"-\n";
            ans = i;
        }
        /*if(i == 13)
        {
            cout<<checkAns()<<"--\n";
        }*/
        
        //cout<<checkAns()<<"-\n";
        //cout<<i<<"--\n";
    }


    cout<<ans<<"\n";
}

int main()
{
    solve();

    return 0;
}