#include<iostream>

using namespace std;

int a[1000], prefix[1000];
int n;

/*
    O(n^2) algorithm
*/

void read()
{
    cin>>n;

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        prefix[i] = a[i] ^ (i > 0 ? prefix[i-1] : 0);
    }
}

int sum_xor_all_subarr()
{
    int i, j, sum = 0;
    for(i = 0;i < n;i++)
    {
        for(j = i;j < n;j++)
            sum += prefix[j] ^ (i > 0 ? prefix[i-1] : 0);
    }

    return sum;
}

int main()
{
    read();
    cout<<sum_xor_all_subarr()<<"\n";
    return 0;
}