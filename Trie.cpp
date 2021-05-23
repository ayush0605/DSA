#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*> mp;
        int wordfreq;
        int prefixfreq;
        bool terminal;

        TrieNode(char data){
            this->data = data;
            wordfreq = 0;
            prefixfreq = 0;
            terminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;
        int totalwords;
        Trie(){
            root = new TrieNode('\0');
            totalwords = 0;
        }

        void insert(string s){
            TrieNode* temp = root;
            for(int i=0;i<s.length();i++){
                if(temp->mp.count(s[i])==1){
                    temp = temp->mp[s[i]];
                    temp->prefixfreq++;
                }
                else{
                    TrieNode* curr = new TrieNode(s[i]);
                    temp->mp[s[i]] = curr;
                    temp = curr;
                }
            }
            temp->terminal = true;
            temp->wordfreq++;
            totalwords++;
        }

        bool find(string s){
            TrieNode* temp = root;
            for(int i=0;i<s.length();i++){
                if(temp->mp.count(s[i])==0){
                    return false;
                }
                else{
                    temp = temp->mp[s[i]];
                }
            }
            return temp->terminal;
        }

        int wordFreq(string s){
            TrieNode* temp = root;
            for(int i=0;i<s.length();i++){
                if(temp->mp.count(s[i])==0){
                    return 0;
                }
                else{
                    temp = temp->mp[s[i]];
                }
            }
            return (temp->terminal == true) ? temp->wordfreq : 0 ;
        }

        string shortestUniquePrefix(string s){
            TrieNode* temp = root;
            int idx = s.length();
            for(int i=0;i<s.length();i++){
                if(temp->mp.count(s[i])==1){
                    temp=temp->mp[s[i]];
                    if(temp->prefixfreq==0){
                        idx = i;
                        break;
                    }
                }
            }
            idx++;
            return s.substr(0,idx);
        }
};


int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    Trie t;
    for(int i=0;i<n;i++){
        cin>>s[i];
        t.insert(s[i]);
    }
    
    string ch = "cat";
    cout<<t.find(ch)<<endl;
    cout<<t.totalwords<<endl;
    cout<<t.shortestUniquePrefix(ch)<<endl;
    cout<<t.wordFreq(ch)<<endl;

    return 0;
}