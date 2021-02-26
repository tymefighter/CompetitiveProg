#include <iostream>
#include <vector>

using namespace std;

const int MAX_X = 1000000;
enum Player {CHEF, DIVYAM};

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> compute_num_primes(int n) {

    vector<int> num_primes(n + 1, 0);
    vector<bool> is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = false;
    for(long long i = 2;i <= n;i++) {
        num_primes[i] = num_primes[i - 1];

        if(!is_prime[i]) continue;

        for(long long j = i * i;j <= n;j += i)
            is_prime[j] = false;

        num_primes[i] ++;
    }

    return num_primes;
}

inline Player predict_winner(
    const vector<int> &num_primes, 
    int X, int Y
) {return Y >= num_primes[X] ? CHEF : DIVYAM;}

int main() {

    enable_fast_io();
    vector<int> num_primes = compute_num_primes(MAX_X);

    int t;
    cin >> t;

    while(t --) {
        int X, Y;
        cin >> X >> Y;
        cout << (predict_winner(
            num_primes, X, Y
        ) == CHEF ? "Chef\n" : "Divyam\n");
    }

    return 0;
}
