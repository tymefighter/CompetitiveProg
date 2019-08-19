#include<iostream>

using namespace std;

int r, g, b;
int n;
bool is_r, is_g, is_b;

void read()
{
    char x;
    cin>>n;
    r = g = b = 0;
    is_r = is_g = is_b = false;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(x == 'R')
            r++;
        else if(x == 'G')
            g++;
        else
            b++;
    }
}

void findAns(int i, int j, int k)
{
    if(i < 0 || j < 0 || k < 0)
        return;

    //cout<<i<<" "<<j<<" "<<k<<"\n";
    
    if(i == 0 && j == 0)
    {
        is_b = true;
        return;
    }
    else if(j == 0 &&  k == 0)
    {
        is_r = true;
        return;
    }
    else if(k == 0 &&  i == 0)
    {
        is_g = true;
        return;
    }



    if(i > 0 && j > 0)
        findAns(i-1, j-1, k+1);
    if(j > 0 && k > 0)
        findAns(i+1, j-1, k-1);
    if(k > 0 && i > 0)
        findAns(i-1, j+1, k-1);
    if(i > 1)
        findAns(i-1, j, k);
    if(j > 1)
        findAns(i, j-1, k);
    if(k > 1)
        findAns(i, j, k-1);
}

void solve()
{
    if((r > 0 && b > 0 && g > 0) || (r > 1 && b > 1) || (b > 1 && g > 1) || (g > 1 && r > 1))
    {
        cout<<"BGR\n";
        return;
    }

    r = (r > 2 ? 2 : r);
    g = (g > 2 ? 2 : g);
    b = (b > 2 ? 2 : b);
    
    findAns(r, g, b);
    if(is_b)
        cout<<'B';
    if(is_g)
        cout<<'G';
    if(is_r)
        cout<<"R";
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}