#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void print(queue<char> numbers)
    {
        while (!numbers.empty())
        {

            // print the element
            cout << numbers.front() << ", ";

            // pop element from the queue
            numbers.pop();
        }

        cout << endl;
    };
    string FirstNonRepeating(string A)
    {
        unordered_map<char, long long int> map;
        queue<char> q;
        string ans = A;
        q.push(A[0]);
        map[A[0]] = 1;
        for (long long  int i = 1; i < A.length(); i++)
        {
            if (map.find(A[i]) != map.end()){
                map[A[i]]++;
            }
            else{
                map[A[i]] = 1;
            }
            q.push(A[i]);
            while (!q.empty()){
                if (map[q.front()] > 1){
                    q.pop();
                }else{
                    ans[i] = q.front();
                    break;
                }
            }
            if (q.empty()){
                ans[i] = '#';
            }
        }
        return ans;
    };
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.FirstNonRepeating("aabc") << endl;
    return 0;
}
