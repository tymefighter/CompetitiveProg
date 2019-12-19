#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int n, T;
vector<vector<int> > a;

void read()
{
    n ++;
    a.clear();
    a.resize(n);

    int boss;
    for(int i = 1;i < n;i++)
    {
        cin>>boss;
        a[boss].push_back(i);
    }
}

int get_opt_num_wk(int u)
{
    if(a[u].size() == 0)
        return 1;
    
    vector<int> workers_opt_take;

    for(int v : a[u])
        workers_opt_take.push_back(get_opt_num_wk(v));

    sort(workers_opt_take.begin(), workers_opt_take.end());

    int num_wk = 0, num_to_take = ceil(((double)T / 100.0) * (double)a[u].size());

    for(int i = 0;i < num_to_take;i++)
        num_wk += workers_opt_take[i];
    
    return num_wk;
}


int main()
{
    while(cin>>n>>T)
    {
        if(!(n | T))
            break;
        read();
        cout<<get_opt_num_wk(0)<<"\n";
    }
    return 0;
}