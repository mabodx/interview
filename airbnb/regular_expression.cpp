/*
regular expression
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


class Solution {
public:
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int f[m+1][n+1];
        memset(f,0,sizeof(f));
        
        f[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            if ((i < m && p[i] == '*') || p[i-1] == '*') {
                f[i][0] = f[i-1][0];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[i-1] == '.'  || p[i-1] == s[j-1]) {
                    f[i][j] = f[i-1][j-1];
                } else if (p[i-1] == '*' && i > 1) {
                    if (p[i-2] != s[j-1] || p[i-2] !='.') {
                        f[i][j] = f[i-2][j];
                    } else {
                        f[i][j] = f[i-1][j] | f[i][j-1] | f[i-2][j];
                    } 
                } else if (p[i-1] == '+' && i > 1) {
                    if (p[i-2] == s[j-1] || p[i-2] =='.') {
                        f[i][j] = f[i-1][j] | f[i][j-1];
                    }
                }
            }
        }
        
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
      //          cout << f[i][j];
            }
            cout <<endl;
        }
        cout <<endl;
        
        cout << s << " " << p << " " << f[m][n] << endl;
        return f[m][n] == 1;
    }
};

int main() {
    Solution a;
   /* a.isMatch("aa","a");
    a.isMatch("aa","aa");
    a.isMatch("aaa","aa");
    a.isMatch("aa", "a*");
    a.isMatch("aa", ".*");
    a.isMatch("ab", ".*");
    a.isMatch("aab", "c*a*b"); */
    a.isMatch("a", "b+");
    a.isMatch("a", "a+");
    a.isMatch("aa", "a+");
    a.isMatch("aaa", "a+");
    a.isMatch("baaa", "a+");

    a.isMatch("a", "aa+");
    a.isMatch("abc", "ab.+");
    a.isMatch("abc", "ac.+");
    a.isMatch("abc", "abc.+");
    a.isMatch("abcd", "abc.+");
    a.isMatch("abcdef", "abc.+");
    a.isMatch("abcccc", "abc.+");
    cout<<"Hello";
    return 0;
}
