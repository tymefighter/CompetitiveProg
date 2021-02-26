#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void readInput(
    vector<vector<int> > &neg, 
    vector<vector<int> > &pos,
    map<int, int> &countMap
) {
    int n;
    scanf("%d ", &n);

    neg.resize(n);
    pos.resize(n);

    for(int i = 0;i < n;i++) {
        int m;
        scanf("%d ", &m);
        
        for(int j = 0;j < m;j++) {
            int x;
            scanf("%d ", &x);

            if(x < 0) {
                neg[i].push_back(-x);
                countMap[-x] ++;
            }
            else {
                pos[i].push_back(x);
                countMap[x] ++;
            }
        }
    
        reverse(pos[i].begin(), pos[i].end());
    }
}

inline bool colOcc(int val, map<int, int> &countMap) {
    return countMap[val] > 1;
}

void solve(
    vector<vector<int> > &neg,
    vector<vector<int> > &pos,
    map<int, int> &countMap
) {
    long long numCollisions = 0;

    for(pair<int, int> elemCount : countMap)
        if(elemCount.second > 1) numCollisions ++;

    int n = neg.size();
    for(int i = 0;i < n;i++) {
        vector<int> &negLine = neg[i], &posLine = pos[i];

        while(!negLine.empty() || !posLine.empty()) {
            if(negLine.empty()) {
                numCollisions += 
                    colOcc(posLine.back(), countMap) ? posLine.size() - 1 : 0;

                posLine.pop_back();
            }
            else if(posLine.empty()) {
                numCollisions += 
                    colOcc(negLine.back(), countMap) ? negLine.size() - 1 : 0;

                negLine.pop_back();
            }
            else if(posLine.back() < negLine.back()) {
                numCollisions += 
                    colOcc(posLine.back(), countMap) ? posLine.size() - 1 : negLine.size();

                posLine.pop_back();
            }
            else if(posLine.back() > negLine.back()) {
                numCollisions += 
                    colOcc(negLine.back(), countMap) ? negLine.size() - 1 : posLine.size();

                negLine.pop_back();
            }
            else {
                
                numCollisions += posLine.size() + negLine.size() - 2;

                posLine.pop_back();
                negLine.pop_back();
            }
        }
    }

    printf("%lld\n", numCollisions);
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        vector<vector<int> > neg, pos;
        map<int, int> countMap;

        readInput(neg, pos, countMap);
        solve(neg, pos, countMap);
    }

    return 0;
}
