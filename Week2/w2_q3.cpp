You said:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool fn(const vector<pair<int,int>> &arr, int target, int &idx1, int &idx2) {
    int l = 0;
    int r = (int)arr.size() - 1;

    while (l < r) {
        int sum = arr[l].first + arr[r].first;
        if (sum == target) {
            idx1 = arr[l].second + 1;
            idx2 = arr[r].second + 1;
            return true;
        }
        else if (sum < target) {
            l++;
        } else {
            r--;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    vector<pair<int,int>> vals(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        vals[i] = {x, i};
    }

    sort(vals.begin(), vals.end());

    bool found = false;
    int a = -1, b = -1, c = -1;

    for (int i = 0; i < n - 1; i++) {
        int rem = target - vals[i].first;
        vector<pair<int,int>> sub(vals.begin() + i + 1, vals.end());

        if (fn(sub, rem, a, b)) {
            c = vals[i].second + 1;
            found = true;
            break;
        }
    }

    if (found) {
        cout << c << ' ' << a << ' ' << b << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
