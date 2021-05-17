#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

vector<bool> is_prime;
vector<long long> primes;

void sieve(long long k) {
    int n = sqrt(k) + 1; 
    is_prime.assign(n + 1, true);

    for(int i = 2;i <= n;i++) {
        if(!is_prime[i]) continue;

        for(long long j = i * static_cast<long long>(i); j <= n;j += i)
            is_prime[j] = false;

        primes.push_back(i);
    }
}

bool check_prime(long long n) {
    if(n < is_prime.size()) return is_prime[n];

    int i = 0;
    while(i < primes.size() && primes[i] * primes[i] <= n)
        if(n % primes[i ++] == 0) return false;
    
    return true;
}

const long long INF = 1e17;

long long compute_inverse(long long k, int idx) {
    
    if(k == 1) return 1;
    if((idx == -1 || k + 1 > primes[min(idx, (int) primes.size() - 1)]) 
        && check_prime(k + 1)) return k + 1;

    long long inv = INF;
    int i = idx + 1;
    while(i < primes.size() && (primes[i] - 1) * (primes[i] - 1) <= k) {
        long long p = primes[i ++];

        if(k % (p - 1)) continue;
        
        long long m = k / (p - 1), pw = p;        
        
        long long curr_inv = compute_inverse(m, i - 1);
        if(curr_inv < INF) curr_inv *= pw;
        inv = min(inv, curr_inv);

        while(m % p == 0) {
            m /= p;
            pw *= p;

            long long curr_inv = compute_inverse(m, i - 1);

            if(curr_inv < INF) curr_inv *= pw;
            inv = min(inv, curr_inv);
        }
    }

    return inv;
}

int main() {

    is_prime.clear();
    primes.clear();

    long long k;
    cin >> k;

    sieve(k);
    long long inv = compute_inverse(k, -1);
    cout << (inv == INF ? 0 : inv) << "\n";

    return 0;
}