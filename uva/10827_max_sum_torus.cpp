#include<iostream>
#include<cstdio>

using namespace std;

int n;
int a[151][151], cf[151][151];

void read()
{
    int i, j;
    cin>>n;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>a[i][j];
            a[i+n][j+n] = a[i+n][j] = a[i][j+n] = a[i][j];
        }
    }

    for(i = 0;i < 2*n;i++)
    {
        for(j = 0;j < 2*n;j++)
        {
            cf[i][j] = a[i][j];
            if(i > 0)
                cf[i][j] += cf[i-1][j];
            if(j > 0)
                cf[i][j] += cf[i][j-1];
            if(i > 0 && j > 0)
                cf[i][j] -= cf[i-1][j-1];
        }
    }
}

int computeSum2D(int i, int j, int k, int l)
{
    return cf[k][l] + (i > 0 && j > 0 ? cf[i-1][j-1] : 0) - (i > 0 ? cf[i-1][l] : 0) - (j > 0 ? cf[k][j-1] : 0);
}

int maxSumTorus()
{
    int i, j, k, l;
    int val, max_val;
    bool first_comp = true;

    for(i = 0;i < 2*n;i++)
    {
        for(j = 0;j < 2*n; j++)
        {
            for(k = i;k < min(i + n, 2*n);k++)
            {
                for(l = j;l < min(j + n, 2*n);l++)
                {
                    val = computeSum2D(i, j, k, l);
                    if(first_comp == true || val > max_val)
                    {
                        first_comp = false;
                        max_val = val;
                    }
                }
            }
        }
    }

    return max_val;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        cout<<maxSumTorus()<<'\n';
    }
    return 0;
}
