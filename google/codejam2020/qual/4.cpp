#include<iostream>
#include<algorithm>

using namespace std;

void solve10() {
    static int ans[10];

    for(int i = 0;i < 10;i++) {
        cout << i + 1 << endl;
        cin >> ans[i];
    }

    for(int i = 0;i < 10;i++)
        cout << ans[i];
    cout << endl;
}

string neg(const string &s) {
    string ns(s.size(), '\0');

    for(int i = 0;i < s.size();i++) {
        if(s[i] == '1')
            ns[i] = '0';
        else
            ns[i] = '1';
    }

    return ns;
}

string rev(const string &s) {
    string ns = s;
    reverse(ns.begin(), ns.end());
    return ns;
}

void solve20() {
    string a[4], ans[4];

    // 20 operations
    for(int i = 0;i < 4;i++) {
        
        int idx;
        if(i % 2 == 0) {
            idx = i / 2;
        }
        else {
            idx = 4 - (i + 1) / 2;
        }

        a[idx].resize(5);
        ans[idx].resize(5);

        for(int j = 0;j < 5;j++) {
            cout << 5 * idx + j + 1 << endl;
            cin >> a[idx][j];
        }
    }

    string new_a[2];
    
    // 10 operations
    for(int i = 0;i < 2;i++) {
        
        new_a[i].resize(5);

        for(int j = 0;j < 5;j++) {
            cout << 5 * i + j + 1 << endl;
            cin >> new_a[i][j];
        }

        if(new_a[i] == a[i]) {
            ans[i] = new_a[i];
            ans[4 - i - 1] = a[4 - i - 1];
        }
        else if(new_a[i] == neg(a[i])) {
            ans[i] = new_a[i];
            ans[4 - i - 1] = neg(a[4 - i - 1]);
        }
        else if(new_a[i] == rev(a[4 - i - 1])) {
            ans[i] = new_a[i];
            ans[4 - i - 1] = rev(a[i]);
        }
        else {
            ans[i] = new_a[i];
            ans[4 - i - 1] = neg(rev(a[i]));
        }
    }

    for(int i = 0;i < 4;i++)
        cout << ans[i];

    cout << endl;
}

void solve100() {
    string a[20], ans[20];

    // 100 operations
    for(int i = 0;i < 20;i++) {
        
        int idx;
        if(i % 2 == 0) {
            idx = i / 2;
        }
        else {
            idx = 20 - (i + 1) / 2;
        }

        a[idx].resize(5);
        ans[idx].resize(5);

        for(int j = 0;j < 5;j++) {
            cout << 5 * idx + j + 1 << endl;
            cin >> a[idx][j];
        }
    }

    string new_a[10];
    
    // 50 operations
    for(int i = 0;i < 10;i++) {
        
        new_a[i].resize(5);

        for(int j = 0;j < 5;j++) {
            cout << 5 * i + j + 1 << endl;
            cin >> new_a[i][j];
        }

        if(new_a[i] == a[i]) {
            ans[i] = new_a[i];
            ans[20 - i - 1] = a[20 - i - 1];
        }
        else if(new_a[i] == neg(a[i])) {
            ans[i] = new_a[i];
            ans[20 - i - 1] = neg(a[20 - i - 1]);
        }
        else if(new_a[i] == rev(a[20 - i - 1])) {
            ans[i] = new_a[i];
            ans[20 - i - 1] = rev(a[i]);
        }
        else {
            ans[i] = new_a[i];
            ans[20 - i - 1] = neg(rev(a[i]));
        }
    }

    for(int i = 0;i < 20;i++)
        cout << ans[i];

    cout << endl;
}

int main() {
    int t, b;
    cin >> t >> b;
    for(int i = 1;i <= t;i++) {
        switch(b) {
            case 10:
                solve10();
                break;
            case 20:
                solve20();
                break;
            case 100:
                solve100();
                break;
        }

        char result;
        cin >> result;
        if(result == 'N')
            break;
    }
    return 0;
}