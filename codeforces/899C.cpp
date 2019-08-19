#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> g1, g2;

void solve()
{
    if(n == 2)
    {
        cout<<"1\n1 1\n";
        return;
    }

    int min_val = 1, max_val = n;
    bool group = true;

    while(min_val < max_val)
    {
        if(group)
        {
            g1.push_back(min_val);
            g1.push_back(max_val);
        }
        else
        {
            g2.push_back(min_val);
            g2.push_back(max_val);
        }

        group = !group;
        min_val ++, max_val--;
    }


    int sum1 = 0, sum2 = 0;

    for(int x : g1)
        sum1 += x;
    for(int x : g2)
        sum2 += x;

    if(min_val == max_val)
    {
        if(sum1 < sum2)
        {
            g1.push_back(min_val);
            sum1 += min_val;
        }
        else
        {
            g2.push_back(min_val);
            sum2 += min_val;
        }
    }

    cout<<abs(sum1 - sum2)<<"\n";
    cout<<g1.size()<<" ";
    for(int x : g1)
        cout<<x<<" ";
    cout<<"\n";
}

int main()
{
    cin>>n;
    solve();
    return 0;
}