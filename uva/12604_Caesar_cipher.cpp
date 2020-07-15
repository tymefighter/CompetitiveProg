#include<iostream>
#include<vector>

using namespace std;

const int NUM_CHAR = 256;
string a, w, s;
int char2ind[NUM_CHAR]; // given a char, it gives index of char in alphabet a

void readInput() {
    cin >> a >> w >> s;

    for(int i = 0;i < NUM_CHAR;i++)
        char2ind[i] = -1;

    for(int i = 0;i < a.size();i++)
        char2ind[static_cast<unsigned>(a[i])] = i;
}

void shift() {
    for(int i = 0;i < s.size();i++) {
        int idxInAlpha = char2ind[static_cast<unsigned>(s[i])];
        idxInAlpha = (idxInAlpha - 1) % static_cast<int>(a.size());
        if(idxInAlpha < 0)
            idxInAlpha += static_cast<int>(a.size());
        s[i] = a[idxInAlpha];
    }
}

bool is_present() {
    string str = w + "#" + s;
    int n = str.size();
    vector<int> pi(n);

    // compute prefix function
    pi[0] = 0;
    for(int i = 1;i < n;i++) {
        int j = pi[i - 1];

        while(j > 0 && str[j] != str[i])
            j = pi[j - 1];

        if(str[j] == str[i])
            pi[i] = j + 1;
        else
            pi[i] = 0;
    }

    int numOcc = 0;
    for(int i = w.size() + 1;i < n;i++) {
        if(pi[i] == w.size())
            numOcc ++;
    }

    return numOcc == 1;
}

void solve() {

    vector<int> shift_ans;
    if(is_present())
        shift_ans.push_back(0);

    for(int i = 1;i < a.size();i++) {
        shift();
        if(is_present())
            shift_ans.push_back(i);
    }

    if(shift_ans.size() == 0)
        cout << "no solution\n";
    else if(shift_ans.size() == 1)
        cout << "unique: " << shift_ans[0] << "\n";
    else {
        cout << "ambiguous: ";
        for(int j = 0;j < shift_ans.size();j++) {
            if(j)
                cout << " ";
            cout << shift_ans[j];
        }
        cout << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        readInput();
        solve();
    }

    return 0;
}