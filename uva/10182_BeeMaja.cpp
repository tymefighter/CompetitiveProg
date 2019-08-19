#include<iostream>

using namespace std;

int a[100005], b[100005];
int ar[] = {-1, 0, 1, 1, 0, -1};
int ac[] = {0, -1, -1, 0, 1, 1};
int no[] = {1, 1, 1, 1, 2, 1};

void generate_ans(int num)
{
    int r, c, m = 1, i, j, k, p = 2;
    a[0] = b[0] = 0;
    r = a[1] = 0;
    c = b[1] = 1;

    i = 1;
    while(true)
    {
        for(j = 0;j < 6;j++)
        {
            for(k = 0;k < no[j];k++)
            {
                r += ar[j];
                c += ac[j];
                a[p] = r;
                b[p] = c;

                p++;
                if(p > num)
                    return;
            }
            no[j]++;
        }
        i++;
    }
}

int main()
{
    generate_ans(100005);
    int n;
    while(cin>>n)
        cout<<a[n - 1]<<" "<<b[n - 1]<<"\n";
    return 0;
}