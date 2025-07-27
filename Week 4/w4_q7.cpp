#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    const int MAX = 1000005;
    vector<int> grundy(MAX, 0);

    for (int n = 1; n < MAX; ++n) {
        set<int> sett;
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            if (a != b && a > 0 && b > 0) {
                int val = grundy[a] ^ grundy[b];
                sett.insert(val);
            }
        }

        int g = 0;
        while (sett.find(g) != sett.end()) {
            g++;
        }

        grundy[n] = g;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (grundy[n] == 0) {
            cout << "second" << endl;
        } else {
            cout << "first" << endl;
        }
    }

    return 0;
}
