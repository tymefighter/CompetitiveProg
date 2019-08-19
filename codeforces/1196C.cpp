#include<iostream>

using namespace std;

int minx, maxx, miny, maxy;

void read_solve()
{
    miny = minx = -100000;
    maxy = maxx = 100000;

    int n, x, y, f, i, j;

    cin>>n;

    for(i = 0;i < n;i++)
    {
        cin>>x>>y;
        for(j = 0;j < 4;j++)
        {
            cin>>f;
            if(!f)
            {
                if(j == 0)
                    minx = max(minx, x);
                else if(j == 1)
                    maxy = min(maxy, y);
                else if(j == 2)
                    maxx = min(maxx, x);
                else if(j == 3)
                    miny = max(miny, y);
            }
        }
    }

    if(maxx >= minx && maxy >= miny)
        cout<<"1 "<<minx<<" "<<miny<<"\n";
    else
        cout<<"0\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read_solve();
    }
    return 0;
}