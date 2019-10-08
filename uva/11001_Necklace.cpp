#include<iostream>
#include<cmath>

using namespace std;

const double EPS = 1e-5;
int Vtotal, V0;

bool equals(double a, double b)
{
    return abs(a - b) < EPS;
}

void solve()
{
    if(Vtotal <= V0)
    {
        cout<<"0\n";
        return;
    }

    double value, max_val = -1;
    int n, max_n = -1;

    for(n = 1;n <= (Vtotal / V0);n++)
    {
        value = n * sqrt(((double)Vtotal / n) - V0);

        if(value > max_val)
        {
            max_val = value;
            max_n = n;
        }
    }
    int ct = 0;

    for(n = 1;n <= (Vtotal / V0);n++)
    {
        value = n * sqrt(((double)Vtotal / n) - V0);
        if(equals(value, max_val))
        {
            if(++ct > 1)
            {
                cout<<"0\n";
                return;
            }
        }
    }

    cout<<max_n<<"\n";
}

int main()
{
    while(cin>>Vtotal>>V0)
    {
        if(!(Vtotal | V0))
            break;
        
        solve();
    }
    return 0;
}