#include<iostream>
#include<cstdio>
#include<utility>

using namespace std;

long int a[21][21][21], cf[21][21][21];
long int arr[21];
long int orig_val;
int A, B, C;

void read()
{
    int i, j, k;
    orig_val = 0;
    cin>>A>>B>>C;

    for(i = 0;i < A;i++)
    {
        for(j = 0;j < B;j++)
        {
            for(k = 0;k < C;k++)
            {
                cin>>a[i][j][k];
                
                cf[i][j][k] = a[i][j][k];
                if(j > 0)
                    cf[i][j][k] += cf[i][j-1][k];
                if(k > 0)
                    cf[i][j][k] += cf[i][j][k-1];
                if(j > 0 && k > 0)
                    cf[i][j][k] -= cf[i][j-1][k-1];

                orig_val += a[i][j][k];

            }
        }
    }
}

long int kadane()
{
    long int sum = 0, ans;
    bool first_comp = true;

    for(int i = 0;i < A;i++)
    {
        sum += arr[i];
        if(first_comp == true || ans < sum)
        {
            ans = sum;
            first_comp = false;
        }

        if(sum < 0)
            sum = 0;
    }

    return ans;
}

long int compute2D(int ind, int i, int j, int k, int l)
{
    return cf[ind][k][l] + (i > 0 && j > 0 ? cf[ind][i-1][j-1] : 0) - (j > 0 ? cf[ind][k][j-1] : 0) - (i > 0 ? cf[ind][i-1][l] : 0);
}

long int solve()
{
    int i, j, k, l;
    int u;
    long int max_val, val;
    bool first_comp = true;
    pair<pair<int, int>, pair<int, int> > id;

    for(i = 0;i < B;i++)
    {
        for(j = 0;j < C;j++)
        {
            for(k = i;k < B;k++)
            {
                for(l = j;l < C;l++)
                {
                    for(u = 0;u < A;u++)
                        arr[u] = compute2D(u, i, j, k, l);

                    val = kadane();
                    if(first_comp == true || max_val < val)
                    {
                        max_val = val;
                        first_comp = false;
                    }
                }
            }
        }
    }


    return max(max_val, orig_val);
}

int main()
{
    int t, ctt = 0;

    cin>>t;

    while(t--)
    {
        read();
        if(ctt)
            cout<<'\n';
        cout<<solve()<<"\n";
        ctt++;
    }

    return 0;
}