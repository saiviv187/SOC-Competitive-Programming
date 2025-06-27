#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
vector<int> memo;

int countWays(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    if (memo[n] != -1) return memo[n];

    int total = 0;
    for (int i = 1; i <= 6; i++) {
        total = (total + countWays(n - i)) % MOD;
    }

    return memo[n] = total;
}

int main() {
    int n;
    cin >> n;
    memo.assign(n + 1, -1);
    cout << countWays(n) << endl;
    return 0;
}
