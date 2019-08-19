#include<iostream>
#include<string>

using namespace std;

string s, a;

void read()
{
    int line = 0;
    s = "";
    while(getline(cin, a))
    {
        if(a.substr(0, 7) == ".......")
            break;
        if(line)
            s += " ";
        
        s += a;
        line++;
    }
}

int main()
{
    read();
    cout<<s<<"\n";
    return 0;
}