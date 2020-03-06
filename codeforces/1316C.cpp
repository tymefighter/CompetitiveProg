#include<iostream>

using namespace std;

int main()
{
    int n, m, p;
    int a, b, u, v;
    scanf("%d%d%d", &n, &m, &p);

    u = -1;
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a);
        if(u == -1 && a % p != 0)
            u = i;
    }
    v = -1;
    for(int i = 0;i < m;i++)
    {
        scanf("%d", &b);
        if(v == -1 && b % p != 0)
            v = i;
    }

    printf("%d\n", u + v);
    return 0;
}