#include<iostream>
#include<set>

using namespace std;

set<long long> s;

void generate()
{
    long long a = 0, b = 1, c;
    s.insert(0);
    s.insert(1);

    while(c <= 10000000000)
    {
        c = a + b;
        s.insert(c);
        a = b;
        b = c;
    }
}

bool isFibo()
{
    long long n;
    cin>>n;

    return s.find(n) != s.end();
}

int main()
{
    generate();

    int t;
    cin>>t;
    while(t--)
    {
        if(isFibo())
            cout<<"IsFibo\n";
        else
            cout<<"IsNotFibo\n";
    }
    return 0;
}