/*

Airbnb: K Edit Distance
Question:
Given a list of word and a target word, output all the words for each the edit distance with the target no greater than k.

e.g. [abc, abd, abcd, adc], target "ac", k = 1,

output = [abc, adc]

Naive Solution:
A naive solution would be, for each word in the list, calculate the edit distance with the target word. If it is equal or less than k, output to the result list. 

If we assume that the average length of the words is m, and the total number of words in the list is n, the total time complexity is O(n * m^2). 

A better solution with a trie:
The problem with the previous solution is if the given list of the words is like ab, abc, abcd, each time we need to repeatedly calculate the edit distance with the target word. If we can combine the prefix of all words together, we can save lots of time. 


*/
#include <iostream>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Node{
public:
    char ch;
    map<char, Node*> sons;
    bool is;
    Node (){}
    Node (char a){
        ch = a;
        is = false;
    }
    string s;
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node('a');
    }
    
    void insert(string s) {
        Node* now = root;
        for (char c : s) {
            if (now->sons.find(c) == now->sons.end()) {
                now->sons[c] = new Node(c);
            }
            now = now->sons[c];
        }
        now->is = true;
        now->s = s;
    }
    
    vector<string > find(string s, int k) {
        int n = s.size();
        vector<int> vc(n+2,0);
        vector<string> ans;
        for (int i = 0; i <= n; i++) {
            vc[i] = i;
        }
        //cout << s<< endl;
        dfs(root, ans, k, s, vc, 0);
        return ans;
    }
    
    void dfs(Node * now, vector<string>&ans, int k , string s, vector<int>vc, int i) {
        if (now->is) {
            if (vc[s.size()] <= k) {
                ans.push_back(now->s);
            }
            for (int i = 0; i< vc.size(); i++) {
                cout << vc[i] << " ";
            }
            cout << now->s<<endl;
            
        }
        
        
        vector<int> vb(s.size() + 1, 0);
        for (int ni = 0; ni < 26; ni ++) {
            char charch = ni + 'a';
            if (now->sons.find(charch)!=now->sons.end()) {
                vb[0] = vc[0] + 1;
                for (int j = 1; j <= s.size(); j++) {
                    char ch = s[j-1];
                    if (ch == charch) {
                        vb[j] = min(vc[j-1], min(vb[j-1] + 1, vc[j] + 1));
                    } else {
                        vb[j] = min(vc[j-1] + 1, min(vb[j-1] + 1, vc[j] + 1));
                    }
                }
                dfs(now->sons[charch], ans, k, s, vb, i+1);
            }
        }
        
    }
};


vector<string> get1(vector<string> vc, string b, int k) {
    Trie a;
    for (string s : vc) {
        a.insert(s);
    }
    return a.find(b, k);
}

int main() {
    
    vector<string>  a = get1({"abc", "abd", "abcd", "adc", "a","ad","abd","acd"}, "ac", 1);
    for (string s : a) {
        cout << s <<endl;
    }
    return 0;
}
