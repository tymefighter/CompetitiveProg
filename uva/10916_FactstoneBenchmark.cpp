#include<iostream>
#include<cmath>

using namespace std;

int year;
double word_size;

void solve()
{
    word_size = pow(2, 2 + (year - 1960) / 10);
    int n = 1;
    double lf = 0;


    while(lf <= word_size)
    {
        n ++;
        lf += log2(n);
    }

    cout<<n - 1<<"\n";
}

int main()
{
    while(cin>>year)
    {
        if(!year)
            break;
        solve();
    }
    return 0;
}