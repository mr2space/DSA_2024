#include<iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    vector<int>arr = {-2,5,6,7,-1,2};
    int low = 0;
    int high = arr.size()-1;

    while(low<high){
        if (arr[low]>=0){
            low++;
        }else if (arr[high]<0){
            high--;
        }else{
            swap(arr[high], arr[low]);
        }
    }
    for(auto ele:arr){
        cout << ele << " ";
    }
    cout << endl;


    return 0;
}