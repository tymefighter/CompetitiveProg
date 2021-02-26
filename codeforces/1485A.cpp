#include <iostream>

using namespace std;

inline int compute_min_op_bound(int a, int b) {
    int min_op_bound = 1;
    b ++;

    while(a) {
        a /= b;
        min_op_bound ++;
    }

    return min_op_bound;
}

int compute_min_op(int a, int b, int min_op_bound) {
    int min_op = min_op_bound;

    for(
        int num_increment_op = 0;
        num_increment_op < min_op_bound;
        num_increment_op++, b++
    ) {
        int a_temp = a;
        int num_op = num_increment_op;

        while(num_op < min_op_bound && a_temp > 0) {
            a_temp /= b;
            num_op ++;
        }

        min_op = min(min_op, num_op);
    }

    return min_op;
} 

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        int a, b;
        scanf("%d %d ", &a, &b);

        int min_op_bound = compute_min_op_bound(a, b);
        int min_op = compute_min_op(a, b, min_op_bound);

        printf("%d\n", min_op);
    }

    return 0;
}