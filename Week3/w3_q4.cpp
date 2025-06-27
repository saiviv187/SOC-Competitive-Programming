#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long fn(string &str1, string &str2) {
    int m = str1.size();
    int n = str2.size();

    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

    // Base cases
    for (int row = 0; row <= m; ++row) dp[row][0] = row;
    for (int col = 0; col <= n; ++col) dp[0][col] = col;

    // Fill DP table
    for (int row = 1; row <= m; ++row) {
        char ch1 = str1[row - 1];
        for (int col = 1; col <= n; ++col) {
            char ch2 = str2[col - 1];

            if (ch1 == ch2) {
                dp[row][col] = dp[row - 1][col - 1];
            } else {
                long long insertCost = dp[row][col - 1];
                long long deleteCost = dp[row - 1][col];
                long long replaceCost = dp[row - 1][col - 1];
                dp[row][col] = 1 + min({insertCost, deleteCost, replaceCost});
            }
        }
    }

    return dp[m][n];
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    cout << fn(a, b) << endl;

    return 0;
}
