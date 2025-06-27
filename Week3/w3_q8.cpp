#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 1e9;

int main() {
    int len;
    cin >> len;

    vector<int> arr(len), vals;

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
        vals.push_back(arr[i]);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int count = (int)vals.size();

    vector<vector<int>> dp(len, vector<int>(count, INF));
 
    for (int j = 0; j < count; j++) {
        dp[0][j] = abs(arr[0] - vals[j]);
    }

    for (int i = 1; i < len; i++) {
        int minVal = INF;
        for (int j = 0; j < count; j++) {
            if (dp[i - 1][j] < minVal) {
                minVal = dp[i - 1][j];
            }
            dp[i][j] = minVal + abs(arr[i] - vals[j]);
        }
    }

    int ans = dp[len - 1][0];
    for (int j = 1; j < count; j++) {
        if (dp[len - 1][j] < ans) {
            ans = dp[len - 1][j];
        }
    }

    cout << ans << "\n";

    return 0;
}
