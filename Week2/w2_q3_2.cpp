#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int n, target;
    cin >> n >> target;

    vector<pair<int, int>> vals(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vals[i] = {x, i};
    }

    sort(vals.begin(), vals.end());

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = vals[i].first + vals[l].first + vals[r].first;
            if (sum == target) {
                cout << vals[i].second + 1 << ' ' << vals[l].second + 1 << ' ' << vals[r].second + 1 << '\n';
                return 0;
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
