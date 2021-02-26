#include<iostream>
#include<vector>
#include<set>

using namespace std;

void readInput(
    vector<pair<int, int> > &segments,
    vector<int> &points
) {
    int numSeg, numPts;
    cin >> numSeg >> numPts;

    segments.clear();
    segments.resize(numSeg);
    points.clear();
    points.resize(numPts);

    for(int i = 0;i < numSeg;i++)
        cin >> segments[i].first >> segments[i].second;

    for(int i = 0;i < numPts;i++)
        cin >> points[i];
}

void computeNumSeg(
    vector<pair<int, int> > segments,
    const vector<int> &points
) {
    vector<pair<int, int> > pointSort(points.size());
    vector<int> ans(points.size());

    for(int i = 0;i < points.size();i++)
        pointSort[i] = {points[i], i};

    sort(pointSort.begin(), pointSort.end());
    sort(segments.begin(), segments.end());

    int currIdx = 0;
    multiset<int> ms;

    for(int i = 0;i < pointSort.size();i++) {
        int p = pointSort[i].first;
        for(auto it = ms.begin();it != ms.end();) {
            auto nextIt = it;
            nextIt ++;

            if(*it < p)
                ms.erase(it);

            it = nextIt;
        }

        while(
            currIdx < segments.size()
            &&
            segments[currIdx].first <= p
        ) {
            if(p <= segments[currIdx].second)
                ms.insert(segments[currIdx].second);

            currIdx ++;
        }

        ans[pointSort[i].second] = ms.size();
    }

    for(int x : ans)
        cout << x << "\n";
}

int main() {
    vector<pair<int, int> > segments;
    vector<int> points;

    readInput(segments, points);
    computeNumSeg(segments, points);

    return 0;
}
