#include<iostream>
#include<map>

using namespace std;

int num0, num1, n;
map<int, int> balance;

void read_solve()
{
    char x;
    int bal, ans = 0;
    num0 = num1 = 0;
    balance.clear();
    
    cin>>n;
    balance[0] = -1;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(x == '0')
            num0++;
        else
            num1++;
        
        bal = num1 - num0;
        if(balance.find(bal) == balance.end())
            balance[bal] = i;

        ans = max(ans, i - balance[bal]);
    }

    cout<<ans<<"\n";
}

int main()
{
    read_solve();
    return 0;
}