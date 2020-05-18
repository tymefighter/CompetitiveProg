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
    string a1_1(5, '\0'), a2_1(5, '\0'), a3_2(5, '\0'), a4_2(5, '\0');
    string a1_3(5, '\0'), a3_3(5, '\0');
    string ans_first_half, ans_second_half;

    for(int i = 6;i <= 10;i++) {
        cout << i << endl;
        cin >> a1_1[i - 6];
    }

    for(int i = 11;i <= 15;i++) {
        cout << i << endl;
        cin >> a2_1[i - 11];
    }

    for(int i = 1;i <= 5;i++) {
        cout << i << endl;
        cin >> a3_2[i - 1];
    }

    for(int i = 16;i <= 20;i++) {
        cout << i << endl;
        cin >> a4_2[i - 16];
    }

    for(int i = 6;i <= 10;i++) {
        cout << i << endl;
        cin >> a1_3[i - 6];
    }

    for(int i = 1;i <= 5;i++) {
        cout << i << endl;
        cin >> a3_3[i - 1];
    }

    if(a3_3 == a3_2) {
        ans_first_half = a3_3;
        ans_second_half = a4_2;
    }
    else if(a3_3 == neg(a3_2)) {
        ans_first_half = a3_3;
        ans_second_half = neg(a4_2);
    }
    else if(a3_3 == rev(a4_2)) {
        ans_first_half = a3_3;
        ans_second_half = rev(a3_2);
    }
    else {  // neg + rev
        ans_first_half = a3_3;
        ans_second_half = neg(rev(a3_2));
    }

    if(a1_3 == a1_1) {
        ans_first_half = ans_first_half + a1_3;
        ans_second_half = a2_1 + ans_second_half;
    }
    else if(a1_3 == neg(a1_1)) {
        ans_first_half = ans_first_half + a1_3;
        ans_second_half =  neg(a2_1) + ans_second_half;
    }
    else if(a1_3 == rev(a2_1)) {
        ans_first_half = ans_first_half + a1_3;
        ans_second_half =  rev(a1_1) + ans_second_half;
    }
    else {  // neg + rev
        ans_first_half = ans_first_half + a1_3;
        ans_second_half = neg(rev(a1_1)) + ans_second_half;
    }

    cout << ans_first_half << ans_second_half << endl;
}

void solve100() {

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