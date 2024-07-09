#include<iostream>
#include<map>
#include <vector>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    map<int,int> m;
    int maxFreq = 0;
    int maxAns = 0;

    for(int val :arr){
        m[val]++;
        maxFreq = max(maxFreq, m[val]);
    }

    for(int i=0; i<arr.size(); i++){
        if(maxFreq == m[arr[i]]){
            maxAns = arr[i];
            return maxAns;
        }
    }


}