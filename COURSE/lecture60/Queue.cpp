#include<iostream>
#include<queue>


using namespace std;

int main(int argc, char const *argv[])
{
    queue<int> q;
    q.push(17);
    q.push(10);
    cout << q.back() << " " << q.front() << endl;
    q.pop();
    cout << q.back() << " " << q.front() << endl;
    return 0;
}
