#include<iostream>
#include <vector>
using namespace std;


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childs;
    TrieNode(char x){
        data = x;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childs = 0;
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
            root->childs++;
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
    bool startWithUtil(TrieNode*root, string word){
        if(word.size() == 0){
            return true;
        }
        int idx = word[0] - 'a';
        TrieNode * child ;
        if (root->children[idx] != NULL){
            child = root->children[idx];
        }else{
            return false;
        }
        return startWithUtil(child, word.substr(1));
    }
    bool startsWith(string prefix) {
        return startWithUtil(root, prefix);
    }
};


string longestCommonPrefix(vector<string> &arr, int n){
    string ans = "";
    Trie t;
    for(int i=0; i<arr.size(); i++){
        t.insert(arr[i]);
    }
    TrieNode *temp = t.root;
    for(int i = 0; i < arr[0].size(); i++){
        char ch = arr[0][i];
        if (temp->childs == 1){
            ans.push_back(ch);
            temp = temp->children[ch-'a'];
        }else{
            break;
        }
        if (temp->isTerminal == true){
            break;
        }
    }
    return ans;
}