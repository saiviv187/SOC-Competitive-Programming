#include <iostream>
#include <vector>
#include <algorithm> // for max_element

using namespace std;

vector<int> fn(vector<int>& nums, int k) {
    vector<int> result;
    int n = nums.size();

    for (int i = 0; i <= n - k; i++) {
        int maxx = nums[i];
        for (int j = i + 1; j < i + k; j++) {
            if (nums[j] > maxx)
                maxx = nums[j];
        }
        result.push_back(maxx);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = fn(nums, k);

    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}
