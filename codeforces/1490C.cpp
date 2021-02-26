#include <iostream>
#include <cmath>

using namespace std;

inline long long cube(long long n) {return n * n * n;}
inline bool is_cube(long long b) {return cube(cbrt(b)) == b;}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        long long x;
        scanf("%lld ", &x);

        long long a = 1, a_cube = 1;
        bool found_solution = false;
        while(a_cube < x) {
            if(is_cube(x - a_cube)) {
                found_solution = true;
                break;
            }

            a ++;
            a_cube = cube(a);
        }

        if(found_solution) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}