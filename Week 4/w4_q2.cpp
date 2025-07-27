#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll sum(ll l, ll r) {
    const ll inv2 = 500000004;
    ll l = (l % MOD) * ((l + 1) % MOD) % MOD * inv2 % MOD;
    ll r = (r % MOD) * ((r + 1) % MOD) % MOD * inv2 % MOD;
    return (r - l + MOD) % MOD;
}

ll sigma(ll n) {
    ll res = 0;
    for (ll i = 1; i <= n;) {
        ll div_val = n / i;
        ll last = n / div_val;
        res = (res + (sum(i - 1, last) * div_val) % MOD) % MOD;
        i = last + 1;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    cout << sigma(n) << "\n";
}
