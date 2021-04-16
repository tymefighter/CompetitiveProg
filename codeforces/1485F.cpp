#include <iostream>
#include <map>

using namespace std;

const long long MOD = 1000000007;

class VeniceMap {
    private:

    long long key_add, value_sum;
    map<long long, long long> mp;

    public:

    VeniceMap():
        key_add(0), value_sum(0) {}

    void add_to_all_keys(long long add_value) {
        key_add += add_value;
    }

    long long get(long long key) {
        return mp[key - key_add];
    }

    void update(long long key, long long value) {
        mp[key - key_add] = (mp[key - key_add] + value) % MOD;
        value_sum = (value_sum + value) % MOD;
    }

    long long get_value_sum() {return value_sum;}
};

void read_solve() {
    int n;
    cin >> n;
    VeniceMap venice_map;

    int b;
    cin >> b;
    venice_map.update(b, 1);

    for(int i = 1;i < n;i++) {
        int b;
        cin >> b;

        long long zero_val = venice_map.get(0);
        venice_map.add_to_all_keys(b);

        long long value_sum = venice_map.get_value_sum();
        venice_map.update(b, (value_sum - zero_val) % MOD);
    }
    
    long long result = venice_map.get_value_sum();
    if(result < 0) result += MOD;
    cout << result << "\n";
}

int main() {

    int t;
    cin >> t;

    while(t --) read_solve();

    return 0;
}