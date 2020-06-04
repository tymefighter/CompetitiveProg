#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int n, k;
vector<vector<int> > a;

void readInput() {
    cin >> n >> k;
    
    a.clear();
    a.resize(k);
    for(int i = 0;i < k;i++) {
        int c;
        cin >> c;
        a[i].resize(c);
        for(int j = 0;j < c;j++) {
            int idx;
            cin >> idx;
            a[i][j] = idx;
        }
    }
}

int getSize(int low, int high) {
    int sz = 0;
    for(int i = low;i <= high;i++)
        sz += a[i].size();
    return sz;
}

void printIdx(int low, int high) {
    for(int i = low;i <= high;i++) {
        for(int idx : a[i])
            cout << idx << " ";
    }
}

pair<int, int> findMaxSet() {
    int low = 0, high = k - 1, val;

    cout << "? ";
    cout << n << " ";
    for(int idx = 1;idx <= n;idx++)
        cout << idx << " ";
    cout << endl;
    cout.flush();
    cin >> val;

    while(low <= high) {
        if(low == high)
            return {low, val};
            
        int mid = (low + high) >> 1, max_right;
        
        cout << "? ";
        cout << getSize(mid + 1, high) << " ";
        printIdx(mid + 1, high);
        cout << endl;
        cout.flush();

        cin >> max_right;
        if(max_right == -1)
            return {-1, -1};

        if(max_right == val)
            low = mid + 1;
        else
            high = mid;
    }

    return {-1, val};
}

int getMaxNotPart() {
    int val;
    unordered_set<int> partOfSet;
    vector<int> notPart;

    for(int i = 0;i < k;i++) {
        for(int idx : a[i])
            partOfSet.insert(idx);
    }

    for(int idx = 1;idx <= n;idx++) {
        if(partOfSet.find(idx) == partOfSet.end())
            notPart.push_back(idx);
    }

    if(notPart.size() == 0)
        return 0;
        
    cout << "? " << notPart.size() << " ";
    for(int idx : notPart)
        cout << idx << " ";
    cout << endl;
    cout.flush();

    cin >> val;
    return val;
}

bool solve() {
    
    if(k == 1) {
        int max_not_part = getMaxNotPart();
        if(max_not_part == -1)
            return false;

        cout << "! " << max_not_part << endl;
        cout.flush();
       
        string result;
        cin >> result;
        if(result != "Correct")
            return false;

        return true;
    }

    pair<int, int> max_idx_val = findMaxSet();

    if(max_idx_val.second == -1)
        return false;

    if(max_idx_val.first == -1) {
        cout << "! ";
        for(int i = 0;i < k;i++)
            cout << max_idx_val.second << " ";

        cout << endl;
        cout.flush();

        string result;
        cin >> result;
        if(result != "Correct")
            return false;

        return true;
    }

    cout << "? " << n - static_cast<int>(a[max_idx_val.first].size()) << " "; 
    int next_max;
    unordered_set<int> max_set(a[max_idx_val.first].begin(), a[max_idx_val.first].end());
    for(int i = 1;i <= n;i++) {
        if(max_set.find(i) == max_set.end())
            cout << i << " ";
    }
    cout << endl;
    cout.flush();

    cin >> next_max;
    if(next_max == -1)
        return false;

    cout << "! ";
    for(int i = 0;i < k;i++) {
        if(i == max_idx_val.first)
            cout << next_max << " ";
        else
            cout << max_idx_val.second << " ";
    }

    cout << endl;
    cout.flush();

    string result;
    cin >> result;
    if(result != "Correct")
        return false;

    return true;
}


int main() {
    int t;
    cin >> t;
    while(t --) {
        readInput();
        if(!solve())
            break;
    }

    return 0;
}