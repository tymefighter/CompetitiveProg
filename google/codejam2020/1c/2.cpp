#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int u;
char digit[10];

void getDigit(int num, const string &str) {

    int i = 0;
    while(num) {
        digit[num % 10] = str[str.size() - i - 1];
        i ++;
        num /= 10;
    }
}

void queries() {

    map<int, set<string> > m;

    for(int i = 0;i < static_cast<int>(1e4);i++) {
        int m_val;
        string r;
        cin >> m_val >> r;
        m[m_val].insert(r);
    }

    set<string> s;
    for(int i = 1;i <= 99;i++) {
        if(m[i].size() == i && i < 99) {
            s.clear();
            for(string str : m[i])
                s.insert(str);

            for(string str : m[i + 1]) {
                if(s.find(str) == s.end()) {
                    getDigit(i + 1, str);
                    break;
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 1;i <= t;i++) {
        cin >> u;
        queries();
        printf("Case #%d: ", i);
        for(int j = 0;j < 10;j++)
            cout << digit[j];
        cout << "\n";
    }
    return 0;
}