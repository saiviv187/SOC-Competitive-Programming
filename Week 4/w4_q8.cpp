#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll fast_pow(ll base, ll power, ll mod) {
    ll ans = 1;
    base %= mod;
    while (power > 0) {
        if (power & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return ans;
}

ll count(const vector<vector<int>>& primes, ll mod) {
    ll result = 1;
    for (const auto& pair : primes) {
        result = result * (pair[1] + 1) % mod;
    }
    return result;
}

ll sum(const vector<vector<int>>& primes) {
    ll result = 1;
    for (const auto& pair : primes) {
        ll prime = pair[0], exp = pair[1];
        ll numer = fast_pow(prime, exp + 1, MOD) - 1;
        if (numer < 0) numer += MOD;
        ll denom = fast_pow(prime - 1, MOD - 2, MOD);
        ll contrib = numer * denom % MOD;
        result = result * contrib % MOD;
    }
    return result;
}

ll pdt(const vector<vector<int>>& primes) {
    ll expo_sum = 1;
    ll mod_cycle = MOD - 1;
    for (const auto& p : primes) {
        expo_sum = expo_sum * (p[1] + 1) % (2 * mod_cycle);
    }

    ll final_result = 1;
    for (const auto& p : primes) {
        ll prime = p[0], count = p[1];
        ll curr_exp = (count % (2 * mod_cycle)) * (expo_sum % (2 * mod_cycle)) % (2 * mod_cycle);
        curr_exp /= 2;
        final_result = final_result * fast_pow(prime, curr_exp, MOD) % MOD;
    }
    return final_result;
}

int main() {
    int num_factors;
    cin >> num_factors;
    vector<vector<int>> factors(num_factors, vector<int>(2));
    for (int i = 0; i < num_factors; ++i) {
        cin >> factors[i][0] >> factors[i][1];
    }

    cout << count(factors, MOD) << " " << sum(factors) << " "<< pdt(factors) << "\n";

    return 0;
}
