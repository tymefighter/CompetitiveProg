#include<iostream>

using namespace std;

int main()
{
    long long int n, m, a, val1, val2;

    cin>>n>>m>>a;
    val1 = n - a;
    val2 = m - a;

    val1 = (val1 > 0 ? val1 : 0);
    val2 = (val2 > 0 ? val2 : 0);


    if(val1 % a)
        val1 = val1 / a + 1;    // Taking ceil
    else
        val1 = val1 / a;
    if(val2 % a)
        val2 = val2 / a + 1;    // Taking ceil
    else
        val2 = val2 / a;


    cout<<(val1 + 1) * (val2 + 1)<<"\n";

    return 0;
}