#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MountainRange {
    private:

    int n;
    vector<int> h;
    stack<int> s;

    public:

    MountainRange(const vector<int> &h_):
        n(h_.size()),
        h(h_) {
            for(int i = n - 2;i >= 0;i--) {
                if(h[i + 1] > h[i])
                    s.push(i);
            }
        }

    int throw_boulder() {
        if(s.empty()) return -1;

        int idx = s.top();
        h[idx] ++;
        if(h[idx] == h[idx + 1]) s.pop();

        if(idx > 0 && h[idx] > h[idx - 1]) s.push(idx - 1);

        return idx + 1;
    }
};

int main() {

    int t;
    cin >> t;

    while(t --) {
        int n, k;
        cin >> n >> k;

        vector<int> h(n);
        for(int i = 0;i < n;i++) cin >> h[i];

        MountainRange mountain_range(h);

        int idx;
        while(k --) {
            idx = mountain_range.throw_boulder();
            if(idx < 0) break;
        }

        cout << idx << "\n";
    }

    return 0;
}