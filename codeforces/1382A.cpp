#include<iostream>
#include<set>

using namespace std;


int main() {

    int t;
    cin >> t;
    while(t --) {
        int n, m;
        set<int> s;

        cin >> n >> m;
        for(int i = 0;i < n;i++) {
            int x;
            cin >> x;
            s.insert(x);
        }

        bool foundAns = false;
        int ans;
        for(int i = 0;i < m;i++) {
            int x;
            cin >> x;
            if(!foundAns && s.find(x) != s.end()) {
                foundAns = true;
                ans = x;
            }
        }

        if(foundAns) {
            cout << "YES\n";
            cout << "1 " << ans << "\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}