#include<iostream>
#include<vector>
#include<cmath>
#include<set>

using namespace std;

struct Circle {
    double x, y, r;
};

bool intersect (const Circle &a, const Circle &b) {
    double centerDist = hypot(a.x - b.x, a.y - b.y);
    double radSum = a.r + b.r, radDiff = fabs(a.r - b.r);

    return
        (radDiff < centerDist) && (centerDist < radSum);
}

const int N = 105;
int n;
Circle a[N];

void readInput() {
    for(int i = 0;i < n;i++)
        cin >> a[i].x >> a[i].y >> a[i].r;
}

bool belongsToComp(const set<int> &s, int i) {
    for(int j : s) {
        if(intersect(a[j], a[i]))
            return true;
    }
    return false;
}

void mergeSets(set<int> &larger, set<int> &smaller) {
    for(int x : smaller)
        larger.insert(x);
    smaller.clear();
}

int solve() {
    vector<pair<bool, set<int> > > comp;

    for(int i = 0;i < n;i++) {
        int maxSetSizeIdx = -1;
        vector<int> compIdx;
        for(int idx = 0;idx < comp.size();idx ++) {
            if(comp[idx].first && belongsToComp(comp[idx].second, i)) {
                if(
                    maxSetSizeIdx == -1 
                    || 
                    comp[idx].second.size() > comp[maxSetSizeIdx].second.size()
                )
                    maxSetSizeIdx = idx;
                else
                    compIdx.push_back(idx);
            }
        }

        if(maxSetSizeIdx == -1) {
            comp.push_back({true, set<int>()});
            comp[static_cast<int>(comp.size()) - 1].second.insert(i);
        }
        else {
            for(int idx : compIdx) {
                mergeSets(comp[maxSetSizeIdx].second, comp[idx].second);
                comp[idx].first = false;
            }
            
            comp[maxSetSizeIdx].second.insert(i);
        }
    }

    int largestSetSize = 0;
    for(int i = 0;i < comp.size();i++)
        largestSetSize = max(
            largestSetSize,
            static_cast<int>(comp[i].second.size())
        );
    
    return largestSetSize;
}

int main() {
    while(cin >> n) {
        if(n == -1)
            break;
        int largestCompSize = 0;
        if(n > 0) {
            readInput();
            largestCompSize = solve();
        }
        cout    
            << "The largest component contains " 
            << largestCompSize 
            << " ring" 
            << (largestCompSize == 1 ? "" : "s") 
            << ".\n";
    }
    return 0;
}