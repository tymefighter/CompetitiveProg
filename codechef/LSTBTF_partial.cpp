#include<iostream>
#include<cmath>

using namespace std;

int n;
string s;

bool get(int i, long long x)
{
    if(i == min(n, 8))
    {
        if(i != n)
            x += (n - 9);
        long long sq = sqrt(x);
        if(sq * sq == x)
        {
            if(n > 9)
            {
                string a;
                a.assign(n - 9, '1');
                cout<<a;
            }
            
            cout<<s<<"\n";
            s.clear();
            return true;
        }
        return false;
    }

    for(int j = 1;j < 10;j++)
    {
        s.push_back('0' + j);
        if(get(i + 1, x + (j * j)))
            return true;
        s.pop_back();
    }

    return false;
}

int main()
{
    //int m;
    cin>>n;
    //for(n = 1;n <= m;n++)
    (void)get(0, 0);
    return 0;
}