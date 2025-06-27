#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);   

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    
    sort(a.begin(), a.end());

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        x -= a[i].first * (n - i);  
        y += a[i].second;           

    cout << x + y << endl;
    return 0;
}
}