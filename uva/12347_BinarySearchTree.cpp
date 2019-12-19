#include<iostream>
#include<vector>

using namespace std;

vector<int> pre;

void read()
{
    pre.clear();
    int x;
    while(cin>>x)
        pre.push_back(x);
}

void getTree(int p_start, int p_end)
{
    if(p_start > p_end)
        return;

    int u = pre[p_start];

    int p1_start = p_start + 1, p1_end;
    int p2_start, p2_end = p_end;

    int i;
    for(i = p_start + 1;i <= p_end;i++)
    {
        if(pre[i] >= u)
            break;
    }

    p1_end = i - 1;
    p2_start = i;

    getTree(p1_start, p1_end);
    getTree(p2_start, p2_end);
    cout<<u<<"\n";
}

int main()
{
    read();
    getTree(0, pre.size() - 1);
    return 0;
}