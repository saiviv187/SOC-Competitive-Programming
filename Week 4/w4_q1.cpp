#include <iostream>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
 
ll fn(ll a, ll b, ll m) {
    if(a==0 && b!=0)return 0;
    if(a==0 && b==0)return 1;
     
    if (b == 0) return 1 % m;
    ll x = fn(a, b / 2, m);
    ll u = (x * x) % m;
    if (b % 2) return (u * a) % m;
    return u;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;

        ll exp = fn(b, c, MOD-1);
        ll ans = fn(a, exp, MOD);

        cout << ans << '\n';
    }
}
