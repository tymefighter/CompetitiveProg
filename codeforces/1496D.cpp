#include <iostream>
#include <vector>

using namespace std;

const int N = 100000;
int n, a[N];

void read_input() {
    scanf("%d ", &n);

    for(int i = 0;i < n;i++) scanf("%d ", &a[i]);
}

int max_len;
bool monotone_start_inc;
vector<int> monotone;

void compute_monotone() {
    bool is_inc = a[1] > a[0];
    max_len = 2;

    monotone_start_inc = is_inc;

    monotone.push_back(2);

    for(int i = 2;i < n;i++) {
        if(a[i] > a[i - 1]) {
            if(is_inc) monotone.back() ++;
            else {
                is_inc = true;
                monotone.push_back(2);
            }
        }
        else {
            if(is_inc) {
                is_inc = false;
                monotone.push_back(2);
            }
            else monotone.back() ++;
        }

        max_len = max(max_len, monotone.back());
    }
}

int compute_max_count() {
    int max_count = 0;
    for(int x : monotone)
        if(max_len == x) max_count ++;

    return max_count;
}

bool check_nbr() {
    bool is_inc = monotone_start_inc;
    int prev_val = -1;

    for(int x : monotone) {
        if(prev_val != -1 && !is_inc &&
            (x == max_len || prev_val == max_len)) {

            if(x == prev_val) return true;
            else if(!(min(x, prev_val) & 1) || min(x, prev_val) < max(x, prev_val) - 1) return false;
            else return true;
        }
    
        is_inc = !is_inc;
        prev_val = x;
    }

    return false;
}

bool solve() {
    compute_monotone();
    if(!(max_len & 1)) return false;

    int max_count = compute_max_count();
    if(max_count > 2) return false;

    if(max_count == 1 && max_len == n)
        return false;

    return check_nbr();
}

int main() {

    read_input();
    printf("%d\n", solve());

    return 0;
}