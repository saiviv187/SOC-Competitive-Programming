#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    stack<int> st;
    vector<int> dp(n, 0);
    int max_len = 0;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                int pos = st.top();
                st.pop();
                dp[i] = (pos > 0 ? dp[pos - 1] : 0) + (i - pos + 1);
                if (dp[i] > max_len) {
                    max_len = dp[i];
                    count = 1;
                } else if (dp[i] == max_len) {
                    count++;
                }
            }
        }
    }

    if (max_len == 0) {
        cout << "0 1" << endl;
    } else {
        cout << max_len << " " << count << endl;
    }

    return 0;
}
