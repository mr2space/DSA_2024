#include<iostream>
#include <vector>
using namespace std;

vector<int> reverse_array(vector<int>& arr){
    int i = 0;
    int j = arr.size()-1;
    while (i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    return arr;
}



int main(){
    vector<int> arr = {3,4,6,11,7,9};
    reverse_array(arr);
    for(int i =0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}