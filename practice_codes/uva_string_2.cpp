#include<iostream>
#include<string>

using namespace std;

string s, a;    // s: long string, a: string to search for

void read()
{
    getline(cin, s);
    getline(cin, a);
}

void search()
{
    int found = s.find(a, 0);
    while(found != string::npos)
    {
        cout<<found<<"\n";
        found = s.find(a, found + 1);
    }
}

int main()
{
    read();
    search();
    return 0;
}