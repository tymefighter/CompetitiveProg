#include<iostream>

using namespace std;

int m, n;
string p, t;
int b[1000005];

void kmpPreprocess()
{
    int i = 0, j = -1;
    b[0] = -1;
    while(i < m)
    {
        while(j >= 0 && p[i] != p[j])
            j = b[j];
        i++, j++;
        b[i] = j;
    }
}

int kmpSearch()
{
    int i = 0, j = 0, ans = 0;
    
    while(i < n)
    {
        while(j >= 0 && t[i] != p[j])
            j = b[j];
        i++, j++;

        if(j == m)
        {
            ans++;
            j = b[j];
        }
    }

    return ans;
}

int main()
{
    while(cin >> p)
    {
        if(p == ".")
            break;
        m = p.size();
        n = 2 * m;
        t = p + p;
        kmpPreprocess();
        cout<<kmpSearch() - 1<<"\n";
    }
}