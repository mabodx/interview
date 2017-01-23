#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

/*
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
*/

class Solution {
public:
    bool isvalid(int x, string s) {
        int n = s.size();
        int i = x;
        int j = n -1;
        for (; i < j; i++,j--) {
            if (s[i]!=s[j])
                return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<string, int> mp;
        
        int i , j ;
        i = 0;
        for (string s : words) {
            mp[s] = i++;
        }
        vector<vector<int> > ans;
        int x = 0;
        for(string s: words) {
            string left = "";
            
            for (i = 0; i < (int)s.size() - 1; i++) {
                left = s[i] + left;
                if (mp.find(left)!=mp.end() && isvalid(i+1,s)){
                    if (x!=mp[left])
                        ans.push_back({x,mp[left]});
                }
            }
            
            
            reverse(s.begin(), s.end());
            string right = "";
            for (i =0; i <  (int)s.size() - 1; i++) {
                right += s[i];
                if (mp.find(right)!=mp.end() && isvalid(i+1,s)){
                    if (mp[right]!=x)
                      ans.push_back({mp[right], x});
                }
            }
    
            if (isvalid(0,s) && mp.find("")!=mp.end()) {
                if (x!=mp[""]) {
                    ans.push_back({x,mp[""]});
                
                    ans.push_back({mp[""],x});
                }
            }
            if (mp.find(s)!=mp.end()) {
                if (x!=mp[s])
                    ans.push_back({x,mp[s]});
            }
            x++;
        }
        
        return ans;
    }
};


int main() {
    Solution a ;
    vector<string> vc = {"a", ""};
    vector<vector<int> >ans = a.palindromePairs(vc);
    
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0 ; j< ans[i].size(); j++)
            cout <<ans[i][j] <<" ";
        cout <<endl;
    }
    return 0;
}
