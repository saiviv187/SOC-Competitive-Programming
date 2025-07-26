#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<ll, ll> dp;
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            map<ll, ll> new_dp;
            for (auto it = dp.begin(); it != dp.end(); ++it) {
                ll c = it->first;
                ll ways = it->second;

                ll add = c + a[i];
                ll abs_add = abs(add);

                new_dp[add] = (new_dp[add] + ways) % MOD;
                new_dp[abs_add] = (new_dp[abs_add] + ways) % MOD;
            }
            dp = new_dp;
        }

        ll max_c = 0;
        for (auto it = dp.begin(); it != dp.end(); ++it) {
            max_c = max(max_c, it->first);
        }

        cout << dp[max_c] % MOD << endl;
    }

    return 0;
}
