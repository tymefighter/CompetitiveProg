#include<iostream>
#include<cassert>

using namespace std;

const int MAXN = 55, MAXM = 105;
int N, M, a[MAXM][MAXN], poll_count[MAXN];
bool fruit[MAXN];

void read()
{
    scanf("%d %d", &N, &M);

    for(int i = 0;i < M;i++)
    {
        for(int j = 0;j < N;j++)
        {
            scanf("%d", &a[i][j]);
            a[i][j] --;
        }
    }
}

void solve(int case_no)
{
    for(int i = 0;i < N;i++)
        fruit[i] = true;

    for(int i = 0;i < N - 1;i++)
    {
        for(int j = 0;j < N;j++)
            poll_count[j] = 0;
        
        for(int j = 0;j < M;j++)
        {
            for(int k = 0;k < N;k++)
            {
                if(fruit[a[j][k]])
                {
                    poll_count[a[j][k]] ++;
                    break;
                }
            }
        }

        int to_remove = -1, min_poll_count = -1;
        for(int j = 0;j < N;j++)
        {
            if(fruit[j] && (to_remove == -1 || poll_count[j] < min_poll_count))
            {
                to_remove = j;
                min_poll_count = poll_count[j];
            }
        }

        assert(to_remove != -1);
        fruit[to_remove] = false;
    }

    for(int i = 0;i < N;i++)
    {
        if(fruit[i])
        {
            printf("Case #%d: %d\n", case_no, i + 1);
            break;
        }
    }
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int i = 1;i <= C;i++)
    {
        read();
        solve(i);
    }
    return 0;
}