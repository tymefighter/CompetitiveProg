#include<iostream>

using namespace std;

int n;
int cf[101][101];

void read()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>cf[i][j];
            if(i > 0)
                cf[i][j] += cf[i-1][j];
            if(j > 0)
                cf[i][j] += cf[i][j-1];
            if(i > 0 && j > 0)
                cf[i][j] -= cf[i-1][j-1];
        }
    }
}

int computeSum(int i, int j, int k, int l)
{
    return cf[k][l] + (i > 0 && j > 0 ? cf[i-1][j-1] : 0) - (i > 0 ? cf[i-1][l] : 0) - (j > 0 ? cf[k][j-1] : 0);
}

int solve()
{
    int i, j, k, l;
    int val, max_val;
    bool first_val = true;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            for(k = i;k < n;k++)
            {
                for(l = j;l < n;l++)
                {
                    val = computeSum(i, j, k, l);
                    if(first_val == true || val > max_val)
                    {
                        max_val = val;
                        first_val = false;
                    }
                }
            }
        }
    }

    return max_val;
}

int main()
{
    while(cin>>n)
    {
        read();
        cout<<solve()<<'\n';
    }

    return 0;
}