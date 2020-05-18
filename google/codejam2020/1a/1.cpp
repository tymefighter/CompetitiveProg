#include<iostream>
#include<algorithm>

using namespace std;

int n;
string p[55];

void read() {
    cin >> n;

    for(int i = 0;i < n;i++)
        cin >> p[i];
}

bool solve(int case_no) {

    string pre, suf;

    for(int i = 0;i < n;i++) {
        string temp_pre, temp_suf;
        
        int j;
        for(j = 0;j < p[i].size();j++) {
            if(p[i][j] == '*')
                break;
            temp_pre.push_back(p[i][j]);
        }
        j ++;
        for(;j < p[i].size();j++) {
            temp_suf.push_back(p[i][j]);
        }
        
        if(temp_pre.size() > pre.size())
            pre = temp_pre;
        if(temp_suf.size() > suf.size())
            suf = temp_suf;
    }

    for(int i = 0;i < n;i++) {
        string temp_pre, temp_suf;
        
        int j;
        for(j = 0;j < p[i].size();j++) {
            if(p[i][j] == '*')
                break;
            temp_pre.push_back(p[i][j]);
        }
        j ++;
        for(;j < p[i].size();j++) {
            temp_suf.push_back(p[i][j]);
        }
        
        for(j = 0;j < temp_pre.size();j++) {
            if(temp_pre[j] != pre[j])
                return false;
        }

        for(j = 0;j < temp_suf.size();j++) {
            if(temp_suf[temp_suf.size() - j - 1] != suf[suf.size() - j - 1])
                return false;
        }
    }

    printf("Case #%d: ", case_no);
    cout << pre << suf << "\n";

    return true;
}

int main() {

    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        read();
        if(!solve(i))
            printf("Case #%d: *\n", i);
    }

    return 0;
}