#include<iostream>

using namespace std;

const string I = "IF", E = "ELSE", EI = "END_IF", EP = "ENDPROGRAM";

string s;

long long int countAns()
{
    long long int val = 1, val_if;

    while(cin>>s)
    {
        if(s == I)
        {
            val_if = countAns();    // comes out when it sees an ELSE
            val_if += countAns();   // comes out when it sees an END_IF

            val *= val_if;          // Each if statement allowes for a control branching
        }
        else if(s == E || s == EI || s == EP)
            break;
    }

    return val;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        cout<<countAns()<<"\n";
    return 0;
}