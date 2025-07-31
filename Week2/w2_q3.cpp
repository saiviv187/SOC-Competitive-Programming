#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<pair<int,int>>num_index_map;
    for(int i=0;i<n;i++){
        num_index_map.push_back({nums[i],i+1});
    }
    sort(num_index_map.begin(),num_index_map.end());

    for(int i=0;i<n-2;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            int total=num_index_map[i].first+num_index_map[j].first+num_index_map[k].first;
            if(total==x){
                cout << num_index_map[i].second << " " << num_index_map[j].second << " " << num_index_map[k].second;
                return 0;
            }else if(total >x){
                k--;
            }else{
                j++;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
