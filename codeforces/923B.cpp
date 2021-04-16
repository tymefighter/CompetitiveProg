#include <iostream>
#include <vector>
#include <set>

using namespace std;

class VeniceSet {
    private:

    multiset<long long> s;
    long long add_value;

    public:

    inline void insert(long long x) {s.insert(x - add_value);}

    inline void remove(long long x) {s.erase(s.find(x - add_value));}

    inline void add_to_all(long long add) {add_value += add;}

    inline long long get_min() {return add_value + *s.begin();}

    inline long long size() {return s.size();}

    inline bool empty() {return s.empty();}
};

int main() {

    int n;
    scanf("%d ", &n);

    vector<int> v(n);
    for(int i = 0;i < n;i++) scanf("%d ", &v[i]);

    vector<int> t(n);
    for(int i = 0;i < n;i++) scanf("%d ", &t[i]);

    VeniceSet venice_set;
    for(int i = 0;i < n;i++) {
        venice_set.insert(v[i]);
        
        long long ice_melted = 0;
        while(!venice_set.empty() && venice_set.get_min() <= t[i]) {
            long long min_val = venice_set.get_min();

            ice_melted += min_val;
            venice_set.remove(min_val);
        }

        venice_set.add_to_all(-t[i]);
        ice_melted += t[i] 
            * static_cast<long long>(venice_set.size());

        printf("%lld ", ice_melted);
    }
    printf("\n");

    return 0;
}