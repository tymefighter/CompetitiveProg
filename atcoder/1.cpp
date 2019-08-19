#include<iostream>
#include<map>
#include<algorithm>

using namespace std;
/*
    Does not work
*/

int n, no;
int a[100005];
int b[100005];
map<int, int> m;

void read()
{
    cin>>n;
    no = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        if(m.find(a[i]) == m.end())
        {
            b[no] = a[i];
            no++;
        }
        m[a[i]]++;
    }
    
}

bool check()
{
    if(no > 3)
        return false;

    if(no == 1 && b[0] == 0)
        return true;

    if(no == 2)
    {
        if(b[0] != 0 && b[1] != 0)
            return false;
        
        if(b[0] == 0)
        {
            if(m[b[1]] == 2 * m[b[0]] - 1)
                return true;
            else
                return false;
        }
        else
        {
            if(m[b[0]] == 2 * m[b[1]] - 1)
                return true;
            else
                return false;
        }
    }

    if(no < 3)
        return false;

    for(int i = 0;i < 3;i++)
    {
        if((b[(i + 2) % 3] ^ b[(i + 1) % 3]) != b[i])
            return false;
    }


    int ct = m[b[0]];
    for(auto it = m.begin();it != m.end(); it++)
    {
        if((*it).second != ct)
            return false;
    }

    return true;
}

int main()
{
    read();
    if(check())
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}