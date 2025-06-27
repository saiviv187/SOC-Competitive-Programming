#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int total = 0;

    while (a.size() > 1) {
        sort(a.begin(), a.end());   
        int j = a[0];
        int b = a[1];
        int summ = j + b;
     total += summ;
 
        a.erase(a.begin());
        a.erase(a.begin());
 
        a.push_back(summ);
    }

    cout << total << endl;
    return 0;
}
