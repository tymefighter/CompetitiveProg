#include<iostream>
#include<vector>

using namespace std;

int x;
vector<int> ans;
int steps;

bool is_ans()
{
    int val = x + 1;

    if((val & (-val)) == val)
        return true;
    return false;
}

void print_ans()
{
    cout<<steps<<"\n";

    for(int x : ans)
        cout<<x<<" ";
    
    cout<<"\n";
}

void solve()
{
    if(is_ans())
    {
        cout<<"0\n";
        return;
    }

    int i = 1, j = 0, id;

    while(i << 1 <= x)
    {
        i = i << 1;
        j++;
        if(!(x & i))
            id = j;
    }

    steps = 0;
    while(true)
    {
        i = (1 << (id + 1)) - 1;
        x = x ^ i;
        ans.push_back(id+1);
        steps ++;

        if(is_ans())
        {
            print_ans();
            return;
        }
        
        x ++;
        steps ++;
        if(is_ans())
        {
            print_ans();
            return;
        }


        i = 1 << id;
        while(id >= 0)
        {
            i = i >> 1;
            id--;
            if(!(x & i))
                break;
        }
    }
}


int main()
{
    cin>>x;
    solve();
    return 0;
}