#include<iostream>

using namespace std;

const int N = 55;
int n;
char pre[N], in[N];

void read()
{
    cin>>n;

    for(int i = 0;i < n;i++)
        cin>>pre[i];
    for(int i = 0;i < n;i++)
        cin>>in[i];
}

void getTree(int p_start, int p_end, int i_start, int i_end)
{
    if(p_end < p_start)
        return;

    char u = pre[p_start];

    int p_t1_start, p_t1_end, i_t1_start, i_t1_end;
    int p_t2_start, p_t2_end, i_t2_start, i_t2_end;

    i_t1_start = i_start;
    i_t2_end = i_end;
    for(int i = 0;i < n;i++)
    {
        if(in[i] == u)
        {
            i_t1_end = i - 1;
            i_t2_start = i + 1;
            break;
        }
    }

    p_t1_start = p_start + 1;
    p_t1_end = p_t1_start + (i_t1_end - i_t1_start);

    p_t2_start = p_t1_end + 1;
    p_t2_end = p_t2_start + (i_t2_end - i_t2_start);

    getTree(p_t1_start, p_t1_end, i_t1_start, i_t1_end);
    getTree(p_t2_start, p_t2_end, i_t2_start, i_t2_end);
    cout<<u;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        getTree(0, n - 1, 0, n - 1);
        cout<<"\n";
    }
}