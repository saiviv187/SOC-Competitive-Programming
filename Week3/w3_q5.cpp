#include <iostream>
#include <vector>
using namespace std;

const int lim = 1e6 + 1;
const long long M = 1e9 + 7;
vector<long long> ans(lim);  

void fn() {
    long long a = 1, b = 1;
    ans[1] = (a + b) % M;

    for (int i = 2; i < lim; ++i) {
        long long a1 = (2LL * a + b) % M;
        long long a2 = (4LL * b + a) % M;

        a = a1;
        b = a2;

        ans[i] = (a + b) % M;
    }
}

int main() {
    fn(); 

    int t;
    cin >> t;

    while (t--) {
        int height;
        cin >> height;
        cout << ans[height] << '\n';
    }

    return 0;
}
