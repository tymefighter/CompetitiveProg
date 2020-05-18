#include<iostream>
#include<sstream>

using namespace std;

const long long MOD = static_cast<long long>(1e9);

int idx;
string s;

void increment(char ch, long long &r, long long &c) {
    if(ch == 'N') {
        r = r - 1;
        if(r < 0)
            r = MOD - 1;
    }
    else if (ch == 'S') {
        r = r + 1;
        if(r == MOD)
            r = 0;
    }
    else if(ch == 'E') {
        c = c + 1;
        if(c == MOD)
            c = 0;
    }
    else if(ch == 'W') {
        c = c - 1;
        if(c < 0)
            c = MOD - 1;
    }
}

long long parseDig() {
    string num;
    stringstream ss;
    long long mul_val;

    while(idx < s.size()) {
        if(s[idx] == '(')
            break;
        num.push_back(s[idx]);
        idx ++;
    }

    ss.str(num);    
    ss >> mul_val;
    return mul_val;
}

// parses from '(' till ')' (inclusive)
pair<long, long> parseString() {

    long long r = 0, c = 0;
    idx ++;

    while(idx < s.size()) {

        if('0' <= s[idx] && s[idx] <= '9') {
            long long mul_val = parseDig();

            pair<long, long> pr = parseString();
            long long r_temp = pr.first;
            long long c_temp = pr.second;


            r_temp = (r_temp * mul_val) % MOD;
            c_temp = (c_temp * mul_val) % MOD;

            r = (r + r_temp) % MOD;
            c = (c + c_temp) % MOD;
        }
        else if(s[idx] == ')') {
            idx ++;
            return {r, c};
        }
        else {
            increment(s[idx], r, c);
            idx ++;
        }
    }

    return {r, c};
}

void solve(int case_num) {

    long long r = 0, c = 0;
    idx = 0;

    while(idx < s.size()) {

        if('0' <= s[idx] && s[idx] <= '9') {
            long long mul_val = parseDig();
            
            pair<long, long> pr = parseString();
            long long r_temp = pr.first;
            long long c_temp = pr.second;

            r_temp = (r_temp * mul_val) % MOD;
            c_temp = (c_temp * mul_val) % MOD;

            r = (r + r_temp) % MOD;
            c = (c + c_temp) % MOD;
        }
        else {
            increment(s[idx], r, c);
            idx ++;
        }
    }

    printf("Case #%d: %lld %lld\n", case_num, c + 1, r + 1);
}

int main() {

    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        cin >> s;
        solve(i);
    }
    return 0;
}