#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long fn(const vector<long long> &wgt, const vector<long long> &val, long long cap, long long ind, vector<vector<long long>> &memo) {
    if (ind == 0 || cap == 0) {
        return 0;
    }

    if (memo[ind][cap] != -1) {
        return memo[ind][cap];
    }

    long long take = 0;
    if (wgt[ind - 1] <= cap) {
        take = val[ind - 1] + fn(wgt, val, cap - wgt[ind - 1], ind - 1, memo);
    }
    long long notTake = fn(wgt, val, cap, ind - 1, memo);

    return memo[ind][cap] = max(take, notTake);
}

long long knapsack(const vector<long long> &wgt, const vector<long long> &val, long long cap) {
    long long n = wgt.size();
    vector<vector<long long>> memo(n + 1, vector<long long>(cap + 1, -1));
    return fn(wgt, val, cap, n, memo);
}

int main() {
    long long n, cap;
    cin >> n >> cap;

    vector<long long> wgt(n);
    vector<long long> val(n);

    for (long long i = 0; i < n; ++i) {
        cin >> wgt[i] >> val[i];
    }

    cout << knapsack(wgt, val, cap) << "\n";

    return 0;
}
