#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    scanf("%d ", &t);

    while(t --) {
        int n;
        scanf("%d ", &n);

        int prev_val, curr_val, num_add = 0;
        scanf("%d ", &prev_val);

        for(int i = 1;i < n;i++) {
            scanf("%d ", &curr_val);

            int min_val, max_val;
            if(curr_val > prev_val) {
                max_val = curr_val;
                min_val = prev_val;
            } else {
                max_val = prev_val;
                min_val = curr_val;
            }

            int pow = static_cast<int>(log2(
                static_cast<double>(max_val) / min_val
            ));
            num_add += pow;

            if(pow > 0 && (1 << pow) * min_val == max_val)
                num_add --;

            prev_val = curr_val;
        }

        printf("%d\n", num_add);
    }

    return 0;
}