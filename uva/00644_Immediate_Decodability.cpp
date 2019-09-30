#include<iostream>
#include<vector>

using namespace std;

string s;
vector<string> a;

void read()
{
    while(s[0] != '9')
    {
        a.push_back(s);
        cin>>s;
    }
}

bool is_prefix(int i, int j)
{
    if(a[i].size() > a[j].size())
        return false;
    
    for(int k = 0;k < a[i].size();k++)
    {
        if(a[i][k] != a[j][k])
            return false;
    }
    return true;
}

bool isImmDec()
{
    int i, j;
    for(i = 0;i < a.size();i++)
    {
        for(j = 0;j < a.size();j++)
        {
            if(i == j)
                continue;
            if(is_prefix(i, j))
                return false;
        }
    }

    return true;
}

int main()
{
    int sno = 1;
    while(cin>>s)
    {
        a.clear();
        read();
        if(isImmDec())
            printf("Set %d is immediately decodable\n", sno);
        else
            printf("Set %d is not immediately decodable\n", sno);
        sno ++;
    }
    return 0;
}