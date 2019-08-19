#include<iostream>

using namespace std;

long long int countt[77];

void count_all()
{
    countt[0] = 0;
    countt[1] = 1;
    countt[2] = 1;

    for(int i = 3;i <= 77;i++)
        countt[i] = countt[i - 2] + countt[i - 3];
}

int main()
{
    count_all();
    int n;
    while(cin>>n)
        cout<<countt[n] + countt[n - 1]<<"\n";
    return 0;
}