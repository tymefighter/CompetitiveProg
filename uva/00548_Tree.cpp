#include<iostream>
#include<sstream>

using namespace std;

const int N = 10005;
stringstream ss;
string s;

int n, inord[N], post[N];

void read()
{
    n = 0;
    while(!ss.eof())
    {
        ss >> inord[n];
        n ++;
    }

    getline(cin, s);
    ss.clear();
    ss.str(s);
    for(int i = 0;i < n;i++)
        ss >> post[i];
}

int ans, ans_val;

void solveTree(int val, int i_start, int i_end, int p_start, int p_end)
{
    int u = post[p_end];

    int i_t1_start, i_t1_end, p_t1_start, p_t1_end;
    int i_t2_start, i_t2_end, p_t2_start, p_t2_end;

    i_t1_start = i_start;
    i_t2_end = i_end;
    for(int i = i_start;i <= i_end;i++)
    {
        if(inord[i] == u)
        {
            i_t1_end = i - 1;
            i_t2_start = i + 1;
            break;
        }
    }

    p_t1_start = p_start;
    p_t1_end = p_t1_start + (i_t1_end - i_t1_start);

    p_t2_start = p_t1_end + 1;
    p_t2_end = p_end - 1;

    bool isLeftEmpty = false, isRightEmpty = false;

    val += u;
    if(i_t1_start <= i_t1_end)
        solveTree(val, i_t1_start, i_t1_end, p_t1_start, p_t1_end);
    else
        isLeftEmpty = true;

    if(i_t2_start <= i_t2_end)
        solveTree(val, i_t2_start, i_t2_end, p_t2_start, p_t2_end);
    else
        isRightEmpty = true;

    if(isLeftEmpty && isRightEmpty)
    {
        if(ans == -1 || val < ans_val)
        {
            ans_val = val;
            ans = u;
        }
        else if(val == ans_val && u < ans)
            ans = u;
    }
}

void solve()
{
    ans = ans_val = -1;
    solveTree(0, 0, n - 1, 0, n - 1);
    cout<<ans<<"\n";
}

int main()
{
    while(getline(cin, s))
    {
        ss.clear();
        ss.str(s);
        read();
        solve();
    }

    return 0;
}