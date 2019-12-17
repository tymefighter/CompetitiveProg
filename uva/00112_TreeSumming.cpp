#include<iostream>
#include<vector>

using namespace std;

int req_sum_val;
bool foundVal;

bool parseTree(int val, bool scanOpenBracket)       // returns if the found tree was empty
{
    char c;
    string s;

    if(scanOpenBracket)
        cin>>c;

    cin>>c;
    if(c == ')')
        return true;

    s.push_back(c);
    while(cin>>c)
    {
        if(c == '(')
            break;
        s.push_back(c);
    }

    val += stoi(s);

    bool left_empty = parseTree(val, false);
    bool right_empty = parseTree(val, true);
    if(left_empty && right_empty)
    {
        if(val == req_sum_val)
            foundVal = true;
    }
    cin>>c;
    return false;
}

int main()
{
    while(cin>>req_sum_val)
    {
        foundVal = false;
        parseTree(0, true);
        
        if(foundVal)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}