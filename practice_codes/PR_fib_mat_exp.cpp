#include<iostream>

using namespace std;

typedef struct FibMat {
    int a[2][2];
} FibMat;

FibMat fib_mul(FibMat u, FibMat v)
{
    FibMat m;
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            m.a[i][j] = 0;
            for(int k = 0;k < 2;k++)
                m.a[i][j] += u.a[i][k] * v.a[k][j];
        }
    }
    return m;
}

int Fib(int n)
{
    if(n == 0)
        return 0;

    FibMat f = {.a[0][0] = 1, .a[0][1] = 1, .a[1][0] = 1, .a[1][1] = 0};
    FibMat res = {.a[0][0] = 1, .a[0][1] = 0, .a[1][0] = 0, .a[1][1] = 1};
    while(n)
    {
        if(n & 1)
            res = fib_mul(res, f);

        f = fib_mul(f, f);
        n >>= 1;
    }

    return res.a[0][0];
}

int main()
{
    int x;
    while(scanf("%d", &x))
    {
        if(x == -1)
            break;
        printf("Fib: %d\n", Fib(x));
    }
    return 0;
}