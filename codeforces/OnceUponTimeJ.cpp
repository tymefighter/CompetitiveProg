#include<iostream>
#include<cmath>
 
using namespace std;
 
long long extendedEuclid(long long a, long long b, long long &x, long long &y)
{
    if(a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
 
    long long x1, y1, g;
    g = extendedEuclid(b % a, a, x1, y1);
 
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}
 
long long n, m, a, k;

 
bool solve()
{
    long long x, y, g, r;
    
    g = extendedEuclid(m, -a, x, y);
    
    if(g < 0)
    {
    	x = -x;
    	y = -y;
    	g = -g;
    }
 
    r = k - n;
    if(r % g)
        return false;
 
    x *= r / g;
    y *= r / g;
 
    long long val = min(floor(g * x / (double)a), floor(g * y / (double)m));
    x = x - val * (a / g);
 
    printf("%lld\n", n + m * x);
    return true;
}
 
int main()
{
    while(cin>>n>>m>>a>>k)
    {
        if(!(n | m | a | k))
            break;
        
        k += a; 
        if(!solve())
            printf("Impossible\n");
    }
    return 0;
}