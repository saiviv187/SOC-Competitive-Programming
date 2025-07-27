#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int fn(ll h, ll a, ll b) {
    if (h <= a) return 1;
    return (h - b - 1) / (a - b) + 1;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        vector<int> res;
        ll lo = 1, hi = 1e18;

        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                ll a, b, n;
                cin >> a >> b >> n;

                ll L, R;
                if (n == 1) {
                    L = 1;
                    R = a;
                } else {
                    L = (n - 2) * (a - b) + a + 1;
                    R = (n - 1) * (a - b) + a;
                }

                if (L > hi || R < lo) {
                    res.push_back(0);
                } else {
                    lo = max(lo, L);
                    hi = min(hi, R);
                    res.push_back(1);
                }
            } else {
                ll a, b;
                cin >> a >> b;
                int n1 = fn(lo, a, b);
                int n2 = fn(hi, a, b);
                if (n1 == n2)
                    res.push_back(n1);
                else
                    res.push_back(-1);
            }
        }

        for (int x : res)
            cout << x << " ";
        cout << '\n';
    }

}
