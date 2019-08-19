#include<iostream>
#include<string>

using namespace std;

const string qwerty = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
const string shiftq = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
const string dvorak = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
string shiftd;
int shift_map[300], m[300];

string s;

void generate_mapping()
{
    int i;
    for(i = 0;i < qwerty.size();i++)
        shift_map[qwerty[i]] = shiftq[i];

    shiftd.resize(qwerty.size());
    for(i = 0;i < dvorak.size();i++)
        shiftd[i] = shift_map[dvorak[i]];
    
    for(i = 0;i < qwerty.size();i++)
        m[qwerty[i]] = dvorak[i];
    
    for(i = 0;i < shiftq.size();i++)
        m[shiftq[i]] = shiftd[i];
}

void solve()
{
    for(char x : s)
    {
        if(x == ' ')
            cout<<x;
        else
            cout<<(char)m[x];
    }
    cout<<"\n";
}

int main()
{
    generate_mapping();
    while(getline(cin, s))
        solve();
    return 0;
}