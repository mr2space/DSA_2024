#include <iostream> 
#include <string>
#include<map>
#include <queue>

using namespace std;

class compare{
    public:
    bool operator()(pair<int, char> a, pair<int, char> b){
	    return a.first < b.first;
    }
};

string reArrangeString(string &s)
{
	map<char, int> freq;
	for(int i =0; i < s.size(); i++){
        if(freq.find(s[i]) != freq.end()){
            freq[s[i]]++;
        }else{
            freq[s[i]] = 1;
        }
	}
    priority_queue<pair<int, char>, vector<pair<int, char>>, compare> pq;
    pair<int, char> previousEle = make_pair<int,char>(-1,'-');
    pair<int, char> temp;
    string ans;
	int count = 0;
    for(auto i:freq){
        temp.first = i.second;
        temp.second = i.first;
        pq.push(temp);
    }
	while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        ans += temp.second;
        temp.first--;
        if (previousEle.first > 0){
            pq.push(previousEle);
        }
        previousEle = temp;
	}

    if (ans.size() != s.size()) return "not possible";
    return ans;

}
