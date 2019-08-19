#include<iostream>

using namespace std;

int solve(int x)
{


    if(x % 4 == 0)                      // Use all 4's
        return x / 4;
    else if((x % 4 == 2) && x >= 6)     // Use (x / 4)-1 4's and one 6
        return x / 4;
    else if((x % 4 == 1) && x >= 9)     // Use (x - 9)/4 4's and one 9
        return (x - 9) / 4 + 1;         // 9 = 9 (1)
    else if((x % 4 == 3) && x >= 15)    // Use (x - 15)/4 4's and one 15 (i.e. 6 + 9)
        return (x - 15) / 4 + 2;        // 15 = 6 + 9 (2)
    else
        return -1;
}

int main()
{
    int t, x;
    cin>>t;

    while(t--)
    {
        cin>>x;
        cout<<solve(x)<<"\n";
    }
    return 0;
}