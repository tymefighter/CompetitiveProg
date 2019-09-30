#include<iostream>

using namespace std;

int expression(int i, int j);
int component(int i, int j);
int factor(int i, int j);

bool isError;
string s;

int expression(int i, int j)
{
    if(i > j || isError)
    {
        isError = true;
        return -1;
    }

    int numPar = 0;
    for(int k = i;k <= j;k++)
    {
        if(numPar < 0)
        {
            isError = true;
            return -1;
        }
        if(s[k] == '(')
            numPar ++;
        else if(s[k] == ')')
            numPar --;
        else if(s[k] == '+' && numPar == 0)
            return component(i, k - 1) + expression(k + 1, j);
    }

    return component(i, j);
}

int component(int i, int j)
{
    if(i > j || isError)
    {
        isError = true;
        return -1;
    }

    int numPar = 0;
    for(int k = i;k <= j;k++)
    {
        if(numPar < 0)
        {
            isError = true;
            return -1;
        }
        if(s[k] == '(')
            numPar ++;
        else if(s[k] == ')')
            numPar --;
        else if(s[k] == '*' && numPar == 0)
            return factor(i, k - 1) * component(k + 1, j);
    }

    return factor(i, j);
}

int factor(int i, int j)
{
    if(s[i] == '(')
        return expression(i + 1, j - 1);

    int ans = 0, pw = 1;

    for(int k = j;k >= i;k --)
    {
        if(s[k] < '0' || s[k] > '9')
        {
            isError = true;
            return -1;
        }
        ans += (s[k] - '0') * pw;
        pw *= 10;
    }

    return ans;
}

int main()
{
    int t, ans;
    cin>>t;
    while(t--)
    {
        cin>>s;
        isError = false;
        ans = expression(0, s.size() - 1);
        if(!isError)
            cout<<ans<<"\n";
        else
            cout<<"ERROR\n";
    }
    return 0;
}