#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int SIZE = 2000005;

ll fact[SIZE], inv_fact[SIZE];

ll power(ll x, ll y) {
    ll ans = 1;
    while (y > 0) {
        if (y % 2 == 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        y /= 2;
    }
    return ans;
}

void compute() {
    fact[0] = 1;
    for (int i = 1; i < SIZE; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv_fact[SIZE - 1] = power(fact[SIZE - 1], MOD - 2);
    for (int i = SIZE - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    ll top = fact[n];
    ll bottom = (inv_fact[r] * inv_fact[n - r]) % MOD;
    return (top * bottom) % MOD;
}

int main() {
    compute();

    ll n, m;
    cin >> n >> m;

    ll final_ans = nCr(n + m - 1, n - 1);   
    cout << final_ans << endl;

    return 0;
}
