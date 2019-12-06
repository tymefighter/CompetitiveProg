#include<iostream>

using namespace std;

int n, m, b[1005];  // reset / back table
string p, t;

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

void kmpSearch()
{
    int i = 0, j = 0;
    while(i < n)
    {
        while(j >= 0 && t[i] != p[j])
            j = b[j];
        i++, j++;
        if(j == m)
        {
            cout<<i - j<<"\n";
            j = b[j];
        }
    }
}

int main()
{
    getline(cin, t);
    n = t.size();
    getline(cin, p);
    m = p.size();
    kmpPreprocess();
    kmpSearch();
    return 0;
}
