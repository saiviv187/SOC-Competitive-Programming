#include <iostream>
using namespace std;
 
int fn(int num) {
    int max = 0;
    int min = 9;
    while (num > 0) {
        int dig = num % 10;
        if (dig > max) {
            max = dig;
        }
        if (dig < min) {
            min = dig;
        }
        num /= 10;
    }
    return max - min;
}

int main() {
    int numt;
    cin >> numt;
    
    while (numt--) {
        int start, end;
        cin >> start >> end;
        
        int lucky_num = start;
        int max_luck = 0;
         
        for (int x = start; x <= end; ++x) {
            int currentLuck = fn(x);
            if (currentLuck > max_luck) {
                max_luck = currentLuck;
                lucky_num = x;
            }
        }
        
        cout << lucky_num << endl;
    }
    
    return 0;
}
