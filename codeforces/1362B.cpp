#include<iostream>
#include<unordered_set>

using namespace std;

const int N = 1025;
int n, a[N];

void readInput() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);
}

int solve() {
    for(int i = 1;i < 1024;i++) {
        unordered_multiset<int> s;
        for(int j = 0;j < n;j++)
            s.insert(a[j]);

        bool found = true;
        for(int j = 0;j < n;j++) {
            auto it = s.find(a[j] ^ i);
            if(it == s.end()) {
                found = false;
                break;
            }

            s.erase(it);
        }

        if(found)
            return i;
    }

    return -1;
}

int main() {
    int t;
    scanf("%d ", &t);

    while(t --) {
        readInput();
        cout << solve() << "\n";
    }

    return 0;
}