#include<iostream>
#include<cmath>

using namespace std;

int l, r, x, y;
float k;

bool check(float v)
{
    if(ceil(v) == floor(v) && (float)x <= v && v <= (float)y)
        return true;
    
    return false;
}

bool solve()
{
    float a, b;

    for(a = (float)l; a <= (float)r;a += 1.)
    {
        b = a / k;
        if(check(b))
            return true;
    }

    return false;
}

int main()
{
    cin>>l>>r>>x>>y>>k;
    if(solve())
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}