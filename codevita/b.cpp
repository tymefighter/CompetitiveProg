#include<iostream>
#include<sstream>
#include<map>

using namespace std;

map<string, int> sh, sm, cost;

bool performCommand(const string &s) {

    stringstream ss(s);
    string cmdWord, person;

    ss >> cmdWord;
    if(cmdWord != "CMD")
        return false;

    ss >> person;

    if(person == "SM") {
        string cmd;
        ss >> cmd;
        if(cmd == "ADD") {
            string itemName;
            long long qty;
            ss >> itemName >> qty;

            if(sh.find(itemName) != sh.end())
                return false;

            sh[itemName] = qty;
        }
        else(cmd == "REMOVE") {
            string itemName;

        }
        else(cmd == "GET_QTY")
        else(cmd == "INCR")
        else(cmd == "DCR")
        else(cmd == "SET_COST")
        else
            return false;
    }
    else if(person == "S") {
        string cmd;
        ss >> cmd;
        if(cmd == "ADD")
        else(cmd == "REMOVE")
        else(cmd == "INCR")
        else(cmd == "DECR")
        else(cmd == "GET_ORDER_AMOUNT")
        else
            return false;
    }
    else
        return false;
}

int main() {

    string s;

    while(getline(cin, s)) {
        if(s == "END")
            break;
        
        if(!performCommand(s))
            cout << "-1\n";
    }

    return 0;
}