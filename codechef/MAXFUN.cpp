#include <iostream>

using namespace std;

int main() {
    
    int t;
    scanf("%d ", &t);

    while(t --) {
        int n, min_value, max_value;
        scanf("%d ", &n);

        scanf("%d ", &min_value);
        max_value = min_value;

        for(int i = 1;i < n;i++) {
            int x;
            scanf("%d ", &x);
            min_value = min(min_value, x);
            max_value = max(max_value, x);
        }

        printf(
            "%lld\n", 
            static_cast<long long>(max_value - min_value) << 1ll
        );
    }

    return 0;
}
