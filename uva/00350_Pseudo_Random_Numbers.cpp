#include<iostream>

using namespace std;

int Z, L, I, M;

int one(int x)
{
    return (Z * x + I) % M;
}

int two(int x)
{
    return one(one(x));
}


int Floyd_Cycle()
{
    int ld;
    int x, xk, xmu;

    x = two(L);
    xk = one(L);
    while(true)
    {
        if(xk == x)
            break;
        
        xk = one(xk);
        x = two(x);
    }

    x = xk, xmu = L;
    while(true)
    {
        if(xmu == x)
            break;
        x = one(x);
        xmu = one(xmu);
    }


    x = one(xmu), ld = 1;
    while(true)
    {
        if(x == xmu)
            break;
        x = one(x);
        ld++;
    }

    return ld;
}

int main()
{
    int c = 1;
    while(cin>>Z>>I>>M>>L)
    {
        if(!(Z | I | M | L))
            break;
        printf("Case %d: %d\n", c, Floyd_Cycle());
        c++;
    }
    return 0;
}