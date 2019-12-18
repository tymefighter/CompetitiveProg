#include<iostream>

using namespace std;

bool isBalanced;

int getTree()
{
    int wl, dl, wr, dr;
    cin>>wl>>dl>>wr>>dr;

    if(!wl)
        wl = getTree();
    if(!wr)
        wr = getTree();
    
    if(wl * dl != wr * dr)
        isBalanced = false;
    
    return wl + wr;
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        isBalanced = true;
        (void)getTree();
        if(isBalanced)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}