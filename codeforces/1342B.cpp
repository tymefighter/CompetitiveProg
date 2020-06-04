#include<iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T --) {
        string t;
        cin >> t;
        bool contOne = false, contZero = false;
        for(char c : t) {
            if(c == '1')
                contOne = true;
            else
                contZero = true;
        }

        if(contOne && contZero) {
            string s(2 * static_cast<int>(t.size()), ' ');
            bool isOne = t[0] == '1';
            for(int i = 0;i < 2 * t.size();i++) {
                if(isOne)
                    s[i] = '1';
                else
                    s[i] = '0';

                isOne = !isOne;
            }

            cout << s << "\n";
        }
        else
            cout << t << "\n";
    }
    return 0; 
}