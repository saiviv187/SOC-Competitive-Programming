#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool fn(ll num) {
    string s = to_string(num);
    int len = s.size();

    if (len == 1 || s[0] != '1' || s.back() == '9') {
        return false;
    }

    for (int i = 1; i < len - 1; ++i) {
        if (s[i] == '0') {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll val;
        cin >> val;

        cout << (fn(val) ? "YES" : "NO") << '\n';
    }

    return 0;
}
