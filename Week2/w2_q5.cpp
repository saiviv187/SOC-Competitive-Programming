#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long median;
    if (n % 2 == 1) {
        median = arr[n / 2];
    } else {
        median = arr[n / 2];  
    }

    long long total_cost ;
    for (int i = 0; i < n; i++) {
        total_cost = abs(arr[i] - median);
    }

    cout << total_cost << "\n";

    return 0;
}
