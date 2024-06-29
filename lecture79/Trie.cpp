#include<iostream>
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