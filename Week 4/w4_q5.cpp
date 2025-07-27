#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

 
double round_half_even(double val) {
    double scaled = val * 1e6;
    double whole;
    double frac = modf(scaled, &whole);

    if (fabs(frac - 0.5) < 1e-8) {
        
        if (fmod(whole, 2.0) == 0.0) {
            return whole / 1e6;  
        } else {
            return (whole + 1.0) / 1e6; 
        }
    }

    return round(scaled) / 1e6;
}

int main() {
    int n;
    cin >> n;

    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    double total = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a = r[i], b = r[j];
            ll cnt = 0;
            for (int x = 1; x <= a; ++x) {
                cnt += min(b, x - 1);
            }
            total += (double)cnt / (a * b);
        }
    }

    cout << fixed << setprecision(6) << round_half_even(total) << endl;
    return 0;
}
