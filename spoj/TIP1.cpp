#include<iostream>

using namespace std;

const int N = 1e7 + 5;
const double eps = 1e-7;
int eulerPhi[N + 1], ans[N + 1];

double absD(double u)
{
    if(u < 0)
        return -u;
    else
        return u;
}

bool isEqual(const double &a, const double &b)
{
    if(absD(a - b) <= eps)
        return true;
    else
        return false;
}

int ct1[10], ct2[10];

bool isPermutation(int i)
{
    int val1 = i, val2 = eulerPhi[i];
    for(int j = 0;j <= 9;j++)
        ct1[j] = ct2[j] = 0;
    while((val1 != 0) && (val2 != 0))
    {
        ct1[val1 % 10] ++;
        val1 /= 10;
        ct2[val2 % 10] ++;
        val2 /= 10;
    }

    if((val1 != 0) || (val2 != 0))
        return false;

    for(int j = 0;j <= 9;j++)
    {
        if(ct1[j] != ct2[j])
            return false;
    }

    return true;
}

void computeAns()
{
    for(int i = 0;i <= N;i++)
    {
        eulerPhi[i] = i;
    }

    ans[0] = -1;
    ans[1] = -1;
    int next_ans = -1;
    for(int i = 2;i <= N;i++)
    {
        if(eulerPhi[i] == i)
        {
            for(int j = i;j <= N;j += i)
                eulerPhi[j] -= eulerPhi[j] / i;
        }

        ans[i] = next_ans;
        if(isPermutation(i))
        {
            if(ans[i] == -1)
                next_ans = i;
            else
            {
                double ratio_prev = ans[i] / (double) eulerPhi[ans[i]];
                double ratio_curr = i / (double) eulerPhi[i];

                if(isEqual(ratio_curr, ratio_prev))
                    next_ans = i;
                else if(ratio_curr < ratio_prev)
                    next_ans = i;
            }
        }
    }
}

int main()
{
    computeAns();
    int t;
    scanf("%d", &t);
    for(int i = 0;i < t;i++)
    {
        if(i)
            printf("\n");
        int n;
        scanf("%d", &n);
        if(ans[n] == -1)
            printf("No solution.");
        else
            printf("%d", ans[n]);
    }
    return 0;
}