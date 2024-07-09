#include<iostream>
#include <vector>
using namespace std;


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char x){
        data = x;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {

public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insertUtil(TrieNode* root, string word){
        if (word.size() == 0){
            root->isTerminal = true;
            return;
        }
        int idx = word[0] - 'a';
        TrieNode * child ;
        if (root->children[idx] != NULL){
            child = root->children[idx];
        }else{
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    /** Returns if the word is in the trie. */
    bool searchUtil(TrieNode*root, string word){
        if(word.size() == 0){
            return root->isTerminal;
        }
        int idx = word[0] - 'a';
        TrieNode * child ;
        if (root->children[idx] != NULL){
            child = root->children[idx];
        }else{
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    TrieNode* startWithUtil(TrieNode*root, string word){
        if(word.size() == 0){
            return root;
        }
        int idx = word[0] - 'a';
        TrieNode * child ;
        if (root->children[idx] != NULL){
            child = root->children[idx];
        }else{
            return NULL;
        }
        return startWithUtil(child, word.substr(1));
    }
    TrieNode* startsWith(string prefix) {
        return startWithUtil(root, prefix);
    }

    void getSuggestion(TrieNode* root ,string prefix, string temp, vector<string>& ans){
        if (root->isTerminal){
            ans.push_back(prefix+temp);
        }
        for(int i=0; i<26; i++){
            if (root->children[i] != NULL){
                temp.push_back('a'+i);
                getSuggestion(root->children[i], prefix, temp, ans);
                temp = temp.substr(0, temp.size()-1);
            }
        }
    }
};



vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr){
    Trie * tree = new Trie();
    vector<vector<string>> ans;

    for(int i=0; i<contactList.size(); i++){
        tree->insert(contactList[i]);
    }

    TrieNode *prev = tree->root;
    TrieNode * curr = NULL;

    string prefix = "";
    for(int i=0; i<queryStr.size();i++){
        if (prev->children[queryStr[i]-'a'] == NULL) break;
        curr = prev->children[queryStr[i]-'a'];
        prefix += queryStr[i];
        string temp;
        vector<string> res;
        tree->getSuggestion(curr, prefix, temp, res);
        ans.push_back(res);
        prev = curr;
    }
    return ans;

}












int main(){
    vector<string> c = {"cod","coding", "codding", "code","coly"};
    string s = "coding";
    vector<vector<string>> ans = phoneDirectory(c,s);
    for(int i =0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
