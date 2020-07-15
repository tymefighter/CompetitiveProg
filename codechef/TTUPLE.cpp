#include<iostream>
#include<algorithm>

using namespace std;

pair<long long, long long> a[3];

int solve() {
    // ans = 0
    bool allEqual = true;
    for(int i = 0;i < 3;i++) {
        if(a[i].first != a[i].second) {
            allEqual = false;
            break;
        }
    }
    if(allEqual)
        return 0;

    // ans = 1
    bool foundDiff = true;
    long long diff = 0;
    for(int i = 0;i < 3;i++) {                  // All diff either some d or 0
        long long d = a[i].second - a[i].first;
        if(d != 0) {
            if(diff != 0 && diff != d) {
                foundDiff = false;
                break;
            }
            else
                diff = d;
        }
    }
    if(foundDiff)
        return 1;

    bool foundDiv = true;
    long long div = 1;
    for(int i = 0;i < 3;i++) {                  // All div either some d or 1
        if(a[i].first == 0 && a[i].second != 0) {
            foundDiv = false;
            break;
        }
        if(a[i].first != 0 && a[i].second % a[i].first != 0) {
            foundDiv = false;
            break;
        }
        long long d = (a[i].first == 0 ? 1 : a[i].second / a[i].first);
        if(d != 1) {
            if(div != 1 && div != d) {
                foundDiv = false;
                break;
            }
            else
                div = d;
        }
    }
    if(foundDiv)
        return 1;

    // ans = 2
    for(int i = 0;i < 3;i++) {
        if(a[i].first == a[i].second)
            return 2;
    }

    sort(a, a + 3);
    do {
        // add -> add
        // 1 add
        if(a[2].second - a[2].first == a[1].second - a[1].first)
            return 2;
        // 2 add
        if(a[0].second - a[0].first == (a[1].second - a[1].first) + (a[2].second - a[2].first))
            return 2;
        // 3 add

        // add -> mul
        // 1 add
        if(a[2].first != 0 && a[1].first != 0) {
            if(a[2].second % a[2].first == 0 && a[1].second % a[1].first == 0
                && (a[2].second / a[2].first) == (a[1].second / a[1].first))
                return 2;
        }
        // 2 add
        if(a[2].first != 0) {
            if(a[2].second % a[2].first == 0) {
                long long div = a[2].second / a[2].first;
                long long diff = a[1].second - a[1].first;
                if((a[0].first + diff) * div == a[0].second)
                    return 2;

                if(div != 0 && a[1].second % div == 0) {
                    diff = a[1].second / div - a[1].first;
                    if((a[0].first + diff) * div == a[0].second)
                        return 2;
                }
            }
        }
        // 3 add
        long long diff = a[2].second - a[2].first;
        if((a[1].first + diff) != 0) {
            if(a[1].second % (a[1].first + diff) == 0) {
                long long div = a[1].second / (a[1].first + diff);
                if((a[0].first + diff) * div == a[0].second)
                    return 2;
            }
        }

        long long d = a[2].second * a[1].first - a[1].second * a[2].first;
        if((a[1].second - a[2].second) != 0 && d % (a[1].second - a[2].second) == 0) {
            d /= (a[1].second - a[2].second); /////// check this - done
            
            
            if((a[2].first + d) != 0 && a[2].second % (a[2].first + d) == 0) {
                long long div = a[2].second / (a[2].first + d);
        
                if((a[0].first + d) * div == a[0].second)
                    return 2;
            }
        }

        // mul -> mul
        // 1 mul
        if(a[2].first != 0 && a[1].first != 0) {
            if(a[2].second % a[2].first == 0 && a[1].second % a[1].first == 0) {
                if(a[2].second / a[2].first == a[1].second / a[1].first)
                    return 2;
            }
        }
        // 2 mul
        if(a[2].first != 0 && a[1].first != 0 && a[0].first != 0) {
            if(a[2].second % a[2].first == 0 && a[1].second % a[1].first == 0 && a[0].second % a[0].first == 0) {
                long long div0 = a[0].second / a[0].first;
                long long div1 = a[1].second / a[1].first;
                long long div2 = a[2].second / a[2].first;
                if(div2 == div1 * div0)
                    return 2;
            }
        }
        // 3 mul

        // mul -> add
        // 1 mul

        // 2 mul
        diff = a[2].second - a[2].first;
        if(a[1].first != 0) {
            if(a[1].second % a[1].first == 0) {
                long long div = a[1].second / a[1].first;

                if(a[0].first * div + diff == a[0].second)
                    return 2;
            }
        }

        diff = a[2].second - a[2].first;
        if(a[1].first != 0) {
            if((a[1].second - diff) % a[1].first == 0) {
                long long div = (a[1].second - diff) / a[1].first;

                if(a[0].first * div + diff == a[0].second)
                    return 2;
            }
        }
        // 3 mul
        if(a[2].first != 0) {
            if(a[2].second % a[2].first == 0) {
                long long div = a[2].second / a[2].first;
                d = a[1].second - a[1].first * div;

                if(a[0].first * div + d == a[0].second)
                    return 2;
            }
        }

        long long div = a[2].second - a[1].second;
        if((a[2].first - a[1].first) != 0 && div % (a[2].first - a[1].first) == 0) { ////////// check this - done
            div /= (a[2].first - a[1].first);
            d = a[2].second - a[2].first * div;

            if(a[0].first * div + d == a[0].second)
                return 2;
        }
        
    } while(next_permutation(a, a + 3));
    
    // ans = 3
    return 3;
}

int main() {

    int t;
    cin >> t;
    while(t --) {
        
        for(int i = 0;i < 3;i++)
            cin >> a[i].first;
        for(int i = 0;i < 3;i++)
            cin >> a[i].second;

        cout << solve() << "\n";
    }
    return 0;
}