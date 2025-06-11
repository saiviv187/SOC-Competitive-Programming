#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int n; cin>>n;
    int arr[n];
    int maxx=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     unordered_map<int, int> map;
     
     int l=0;
    for(int i=0;i<n;i++){
        if(map.find(arr[i])!=map.end()){
            l = max(l, map[arr[i]] + 1);

            map[arr[i]]=i;
        }
        else{map[arr[i]]=i;}
         
        maxx=max(i-l+1,maxx);
    }
    cout<< maxx;
}


 
