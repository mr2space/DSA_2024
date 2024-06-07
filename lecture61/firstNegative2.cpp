#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void print(vector<long long> ans)
{
    for (auto i : ans)
        std::cout << i << ' ';
    cout << endl;
}

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        
        queue<long long int>index;
        vector<long long> ans;
        for(int idx = 0; idx < K; idx++){
            if(A[idx] < 0){
                index.push(idx);
            }
        }
        if (index.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(A[index.front()]);
        }
        for(int i = K; i < N; i++ ){
            if (A[i]<0){
                index.push(i);
            }
            
            if ((!index.empty()) && (i-K) == index.front()){
                index.pop();
            }
            if (index.empty()){
                ans.push_back(0);
                continue;
            }
            ans.push_back(A[index.front()]);
        }
        return ans;    
 }



 
int main(int argc, char const *argv[])
{
    long long int A[] = {-8, 2, 3, -6, 10};
    int N = 5;
    int K = 2;
    vector<long long int> ans = printFirstNegativeInteger(A, N, K);
    print(ans);
    return 0;
}

 