#include <iostream>
using namespace std;

int main() {
    int n, sum = 0, given_sum = 0, x;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x;
        given_sum += x;
    }
    sum = n * (n + 1) / 2;
    cout << (sum - given_sum) << endl;
    return 0;
}
