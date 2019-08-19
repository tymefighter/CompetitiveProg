#include<iostream>
#include<set>
#include<string>

using namespace std;

int n;
set<string> s;
string a, b;

void remove_amb()
{
    int i, start;
    b = "";
    bool prev_k = false;
    for(i = 0;i < a.size();i++)
    {
        if(a[i] == 'k')
        {
            if(!prev_k)
            {
                prev_k = true;
                start = i;
            }
        }
        else if(a[i] == 'h' && prev_k)
        {
            b.push_back('h');
            prev_k = false;
        }
        else
        {
            if(prev_k)
            {
                b.append(a.substr(start, i - start));
                prev_k = false;
            }
            if(a[i] == 'u')
            {
                b.push_back('o');
                b.push_back('o');
            }
            else
            {
                b.push_back(a[i]);
            }
        }
    }
    
    if(a[a.size()-1] == 'h' && a[a.size()-2] == 'k')
        return;
    
    if(prev_k)
        b.append(a.substr(start, a.size() - start));
}

void read_solve()
{
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>a;
        remove_amb();
        s.insert(b);
    }
    cout<<s.size()<<"\n";

    /*for(auto it = s.begin();it != s.end();it++)
        cout<<*it<<"\n";*/
}

int main()
{
    read_solve();
    return 0;
}