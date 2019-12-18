#include<iostream>
#include<map>

using namespace std;

map<int, int> m;

bool getTree(int location)
{
    int u;
    cin>>u;

    if(u == -1)
        return false;

    if(m.find(location) == m.end())
        m[location] = 0;
    
    m[location] += u;
    
    (void)getTree(location - 1);
    (void)getTree(location + 1);

    return true;
}

int main()
{
    int case_no = 1;
    while(true)
    {
        m.clear();
        if(!getTree(0))
            break;

        printf("Case %d:\n", case_no);
        int ct = 0;
        for(auto val_pair : m)
        {
            if(ct)
                cout<<" ";
            cout<<val_pair.second;
            ct ++;
        }
        cout<<"\n\n";
        case_no ++;
    }
    return 0;
}