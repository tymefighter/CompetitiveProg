#include<iostream>

using namespace std;

long long int N, a, b;

long long int f(long long int x)
{
    x %= N;
    return (a * ((x * x) % N) + b) % N;
}

long long int floydCycleFinding()
{
    long long int tortoise, hare, lambda;

    tortoise = f(0), hare = f(f(0));

    while(tortoise != hare)     // hare moves at 2x, tortoise moves at 1x (both started at 0)
    {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    hare = 0;
    while(tortoise != hare)     // hare starts at 0, tortoise continues from klambda, both move at 1x
    {
        tortoise = f(tortoise);
        hare = f(hare);
    }

    lambda = 1, hare = f(hare);
    while(tortoise != hare)     // hare starts at mu + 1, tortoise is at mu, only hare moves (at 1x)
    {
        hare = f(hare);
        lambda ++;
    }

    return N - lambda;
}

int main()
{
    while(cin>>N)
    {
        if(!N)
            break;
        cin>>a>>b;
        cout<<floydCycleFinding()<<"\n";
    }
    return 0;
}