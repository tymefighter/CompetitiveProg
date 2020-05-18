#include<iostream>
#include<algorithm>

using namespace std;

typedef struct Event {
    int start, end, index;
} Event;

bool comp_event(const Event &e1, const Event &e2) {
    if(e1.start != e2.start)
        return e1.start < e2.start;
    
    if(e1.end != e2.end)
        return e1.end < e2.end;
    
    return e1.index < e2.index;
}

const int N = 1005;
int n;
Event events[N];

void read() {
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> events[i].start >> events[i].end;
        events[i].index = i;
    }
}

void solve(int case_num) {
    sort(events, events + n, comp_event);

    int finish_c = 0, finish_j = 0;     // Finish times of c and j
    string ans(n, '\0');   // Answer string

    for(int i = 0;i < n;i ++) {

        int start = events[i].start;
        int end = events[i].end;
        int index = events[i].index;

        if(start < finish_c && start < finish_j) {
            cout << "Case #" << case_num << ": IMPOSSIBLE";
            return;
        }
        else if(start >= finish_c && start >= finish_j) {
            
            if(finish_c >= finish_j) {
                ans[index] = 'C';
                finish_c = end;
            }
            else {
                ans[index] = 'J';
                finish_j = end;
            }
        }
        else if(start >= finish_c) {
            ans[index] = 'C';
            finish_c = end;
        }
        else if(start >= finish_j) {
            ans[index] = 'J';
            finish_j = end;
        }
    }

    cout << "Case #" << case_num << ": " << ans;
}

int main() {
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        if(i != 1)
            cout << "\n";
        read();
        solve(i);
    }
    return 0;
}