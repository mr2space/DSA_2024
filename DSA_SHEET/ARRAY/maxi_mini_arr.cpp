#include<iostream>
#include <vector>
using namespace std;

pair<int, int> maximini(vector<int> arr){
    int mini = arr[0];
    int maxi = arr[0];

    for(int i=0; i<arr.size(); i++){
        if (arr[i] < mini){
            mini = arr[i];
        }else if (arr[i] > maxi){
            maxi = arr[i];
        }
    }
    return {mini, maxi};

}



int main(){
    vector<int> arr = {3,4,6,11,7,9};
    pair<int, int> ans = maximini(arr);
    cout << ans.first << " ";
    cout << ans.second << "  ";
    cout << endl;
    return 0;
}