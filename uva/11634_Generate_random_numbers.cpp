#include<iostream>

using namespace std;

const int n = 4;
int a;

int f(int x)
{
    x *= x;
    x /= 100;

    int next = x % 10000;

    return next;
}

int floydCycleFinding()
{
    int tortoise = f(a), hare = f(f(a)), mu, lambda;

    while(tortoise != hare)     // tortoise would contain xklambda
    {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    hare = a, mu = 0;
    while(tortoise != hare)     // hare would contain xmu
    {
        tortoise = f(tortoise);
        hare = f(hare);
        mu ++;
    }

    hare = f(hare), lambda = 1;
    while(tortoise != hare)
    {
        hare = f(hare);
        lambda ++;
    }
    
    return mu + lambda;
}

int main()
{
    while(cin>>a)
    {
        if(!a)
            break;
        cout<<floydCycleFinding()<<"\n";
    }
    return 0;
}