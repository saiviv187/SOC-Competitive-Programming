#include <iostream>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
const int MAX = 1'000'005;
ll fact[MAX], inv_fact[MAX];

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp) {
        if (exp % 2) result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

void fn() {
    fact[0] = 1;
    for (ll i = 1; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], mod - 2, mod);
    for (ll i = MAX - 2; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
}

int main(){
    fn(); 

    ll n;
    cin >> n;

    for(ll i = 1; i <= n; i++){
        ll x, y;
        cin >> x >> y;

        if (y> x) {
            cout << 0 << endl;
            continue;
        }

        ll numer = fact[x];
        ll denom = (fact[y] * fact[x - y]) % mod;
        ll inv_denom = mod_pow(denom, mod - 2, mod);
        ll result = (numer * inv_denom) % mod;

        cout << result << endl;
    }   
}