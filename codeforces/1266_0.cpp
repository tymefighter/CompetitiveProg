#include<iostream>

using namespace std;

string s;

void solve()
{
    bool found_0 = false, found_2 = false;
    int sum_dig = 0;

    for(char x : s)
    {
        if(x == '0' && !found_0)
            found_0 = true;
        else if(((int)(x - '0')) % 2 == 0)
            found_2 = true;
        
        sum_dig += (int)(x - '0');
    }

    if(sum_dig % 3 == 0 
        && found_0 && found_2)
        cout<<"red\n";
    else
        cout<<"cyan\n";    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        solve();
    }
    return 0;
}