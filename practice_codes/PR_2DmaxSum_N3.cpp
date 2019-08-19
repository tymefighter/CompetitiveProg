#include<iostream>
#include<cstdio>

using namespace std;

int m, n;
int a[1000][1000];
int row_sum[1000];
int r1, c1, r2, c2;
int ans;

void read()
{
    int i, j;
    cin>>m>>n;
    for(i = 0;i < m;i++)
    {
        for(j = 0;j < n;j++)
            cin>>a[i][j];
    }
}


void Kadane(int left, int right)
{
    int sum = 0, max_sum = row_sum[0];
    int c_r1 = 0, c_c1 = left, c_r2 = 0, c_c2 = right;
    int row_start = 0;

    for(int i = 0;i < m;i++)
    {
        sum += row_sum[i];
        if(sum > max_sum)
        {
            max_sum = sum;
            c_r1 = row_start;
            c_r2 = i; 
        }

        if(sum < 0)
        {
            row_start = i + 1;
            sum = 0;
        }
    }

    if(max_sum > ans)
    {
        r1 = c_r1, r2 = c_r2;
        c1 = c_c1, c2 = c_c2;
        ans = max_sum;
    }
}

void range_2DmaxSum()
{
    ans = a[0][0];
    r1 = r2 = c1 = c2 = 0;

    int left, right, i;

    for(left = 0;left < n;left++)
    {
        for(right = left;right < n;right++)
        {
            if(left == right)
            {
                for(i = 0;i < m;i++)
                    row_sum[i] = a[i][left];
            }
            else
            {
                for(i = 0;i < m;i++)
                    row_sum[i] += a[i][right];
            }

            Kadane(left, right);
        }
    }
}

int main()
{
    read();
    range_2DmaxSum();

    cout<<ans<<"\n";
    printf("r1: %d, c1: %d, r2: %d, c2: %d\n", r1, c1, r2, c2);
    return 0;
}