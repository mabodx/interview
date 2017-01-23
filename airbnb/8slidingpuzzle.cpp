#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int n = 3;
pair<int, int> findd(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ')
            return make_pair(i/n,i%n);
    }
}

bool valid(int x, int y) {
    if (0 <= x && x < n && 0 <= y && y < n) {
        return true;
    }
    return false;
}

int get(int x, int y) {
    return x*n + y;
}

void print(string s) {
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            cout << s[i*n+j];
        }
        cout <<endl;
    }
    cout <<endl;
}

bool dfs(string& s, string& t, unordered_map<string, int>& mp, int& find) {

    
    if (s == t) {
        find = 1;
        print (s);
        return true;
    } 
    mp[s] =1;
    
    
    queue<string> q;
    q.push(s);
    
    
    while(!q.empty()) {
        pair<int, int> now = findd(s);
        s = q.front();
        if (t == s) {
            return true;
        }
        mp[s] = 1;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + now.first;
            int y = dy[i] + now.second;
            if (valid(x,y)){
                swap(s[get(x,y)], s[get(now.first, now.second)]);
                if (mp[s] == 0) {
                    q.push(s);
                    
                }
                swap(s[get(x,y)], s[get(now.first, now.second)]);
            }
        }
    }
    return false;
}

void solve(string s) {
    string t = "12345678 ";
    
    unordered_map<string, int> mp;
    int find = 0;
    cout << s <<endl;
    cout << dfs(s, t, mp, find);
    cout << "end" <<endl;
}

int main() {
    
    string b = " 57681235 ";
    solve(b);
    return 0;
}
