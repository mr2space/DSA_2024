#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print(vector<long long> ans)
{
    for (auto i : ans)
        std::cout << i << ' ';
    cout << endl;
}


vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    queue<long long int> q;
    int steps = K;
    int idx = K;
    vector<long long> ans;
    for(idx = 0; idx < K; idx++){
        if (K > N && A[idx] < 0 && ans.empty()){
            ans.push_back(A[idx]);
        }
        q.push(A[idx]);
    }
    if (K > N && ans.empty()){
        ans.push_back(0);
    }
    while (idx < N+1)
    {
        while ((q.front() >= 0 ) && (!q.empty()))
        {
            steps--;
            q.pop();
        }
        if (q.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(q.front());
        }
        // ans.push_back(q.front());
        if (steps == K)
        {
            q.pop();
            steps--;
        }
        q.push(A[idx]);
        steps++;
        idx++;
    }
    return ans;
}
 

int main(int argc, char const *argv[])
{
    long long int A[] ={12, -1, -7, 8, -15, 30, 16, 28};
    int N = 8;
    int K = 3;
    vector<long long int> ans = printFirstNegativeInteger(A, N, K);
    print(ans);
    return 0;
}
