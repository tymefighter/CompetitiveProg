#include<iostream>
#include<vector>

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

void build_prefix_seg(
    const vector<pair<int, int> > &segments,
    vector<pair<int, int> > &pre_seg
) {
    for(const pair<int, int> &seg : segments) {
        pre_seg.push_back({seg.first, 1});
        pre_seg.push_back({seg.second + 1, -1});
    }

    sort(pre_seg.begin(), pre_seg.end());

    for(int i = 1;i < pre_seg.size();i++)
        pre_seg[i].second += pre_seg[i - 1].second;
}

int binarySearch(
    int point,
    const vector<pair<int, int> > &pre_seg
) {
    int low = 0, high = static_cast<int>(pre_seg.size()) - 1;
    int ansIdx = -1;

    while(low <= high) {
        int mid = (low + high) >> 1;

        if(pre_seg[mid].first <= point) {
            ansIdx = max(ansIdx, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ansIdx == -1 ? 0 : pre_seg[ansIdx].second;
}

void computeNumSeg(
    const vector<pair<int, int> > &segments,
    const vector<int> &points
) {
    vector<pair<int, int> > pre_seg;
    build_prefix_seg(segments, pre_seg);
    
    for(int p : points)
        cout << binarySearch(p, pre_seg) << "\n";
}

int main() {
    vector<pair<int, int> > segments;
    vector<int> points;

    readInput(segments, points);
    computeNumSeg(segments, points);

    return 0;
}
