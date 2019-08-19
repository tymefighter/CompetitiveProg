#include<iostream>

using namespace std;

int n;
int a, b, c, d, e, f;

int read_solve()
{
    int x, ans = 0;
    cin>>n;
    a = b = c = d = e = f = 0;
    
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(x == 4)
            a++;
        else if(x == 8)
        {
            if(a)
            {
                b++;
                a--;
            }
        }
        else if(x == 15)
        {
            if(b)
            {
                c++;
                b--;
            }
        }
        else if(x == 16)
        {
            if(c)
            {
                d++;
                c--;
            }
        }
        else if(x == 23)
        {
            if(d)
            {
                e++;
                d--;
            }
        }
        else if(x == 42)
        {
            if(e)
            {
                f++;
                e--;
            }
        }
    }

    ans = n - 6 * f;

    return ans;
}

int main()
{
    cout<<read_solve()<<"\n";

    return 0;
}