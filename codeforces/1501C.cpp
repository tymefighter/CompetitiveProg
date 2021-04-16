#include <iostream>
#include <vector>

using namespace std;

const int N = 200000;
int n, arr[N];
vector<vector<pair<int, int> > > a;

void read_input() {
    scanf("%d ", &n);

    int max_val = 0;
    for(int i = 0;i < n;i++) {
        scanf("%d ", &arr[i]);
        max_val = max(max_val, arr[i]);
    }

    a.clear();
    a.resize(2 * max_val + 1);
}

bool compute_and_print_solution(const vector<pair<int, int> > &vec) {

    if(vec.size() == 4) {
        if(vec[0].first == vec[1].first
            && vec[1].first == vec[2].first
            && vec[2].first == vec[3].first) {
                printf("YES\n%d %d %d %d\n", 
                    vec[0].second, vec[1].second, 
                    vec[2].second, vec[3].second);

                return true;
            }
        
        else if(vec[0].second == vec[1].second
            && vec[1].second == vec[2].second
            && vec[2].second == vec[3].second) {
                printf("YES\n%d %d %d %d\n", 
                    vec[0].first, vec[1].first, 
                    vec[2].first, vec[3].first);

                return true;
            }
    }

    for(int i = 0;i < vec.size();i++) {
        for(int j = i + 1;j < vec.size();j++) {
            if(vec[i].first != vec[j].first 
                && vec[i].first != vec[j].second
                && vec[i].second != vec[j].first
                && vec[i].second != vec[j].second) {
                    printf("YES\n%d %d %d %d\n", 
                        vec[i].first, vec[i].second, 
                        vec[j].first, vec[j].second);

                    return true;
                }
        }
    }

    return false;
}

void solve() {
    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            int idx = arr[i] + arr[j];

            a[idx].push_back({i + 1, j + 1});

            if(a[idx].size() == 4) {
                compute_and_print_solution(a[idx]);
                return;
            }
        }
    }

    for(const vector<pair<int, int> > &vec : a) {
        if(compute_and_print_solution(vec))
            return;
    }

    printf("NO\n");
}

int main() {

    read_input();
    solve();

    return 0;
}