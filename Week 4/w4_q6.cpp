#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        int a = 0;
        for (int val : v) {
            a ^= val;
        }

        if (a == 0)
            cout << "second" << '\n';
        else
            cout << "first" << '\n';
    }

    return 0;
}
