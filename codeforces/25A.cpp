#include<iostream>

using namespace std;


int main()
{
    int n, i, ne, no, even, odd, x;
    cin>>n;

    even = odd = -1;
    ne = no = 0;

    for(i = 1;i <= n;i++)
    {
        cin>>x;
        if(x % 2)
        {
            even = i;
            ne++;
        }
        else
        {
            odd = i;
            no++;
        }
    }

    if(ne > 1)
        cout<<odd<<"\n";
    else
        cout<<even<<"\n";
    return 0;
}