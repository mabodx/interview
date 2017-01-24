#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

class node {
public:
    node(){}
    node (string d, int a, int b, string q){
        s = d;
        g = a;
        h = b;
        f = g+h;
        pre = q;
    }
    string s;
    string pre;
    int g,f, h;
};

class cmp {
public:
    bool operator ()(const node a, const node b) const{
        return a.f > b.f;
    }
};


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

int calh(string s) {
    int res;    
    for(int i=0;i<9;i++){
        if(s[i]==' ')
            continue;
        char a = '1' + i;
        if(s[i]!=a){
            res ++;
        }
    }
    return res;
}

bool bfs(string& s, string& t, map<string, node>& mp) {    
    if (s == t) {
        print (s);
        return true;
    } 
    node a= node(s, 0, 0, "");
    mp[s] = a;
    
    
    priority_queue<node, vector<node>, cmp> q;
    q.push(node(s, 0, 0, ""));
    
    
    while(!q.empty()) {
        node top = q.top();
        q.pop();
        
        s = top.s;
        pair<int, int> now = findd(s);
        if (t == s) {
            return true;
        }
        string pre = s;
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + now.first;
            int y = dy[i] + now.second;
            if (valid(x,y)){
                swap(s[get(x,y)], s[get(now.first, now.second)]);
                if (mp.find(s) == mp.end()) {
                    q.push(node(s,top.g+1,calh(s), pre));
                    mp[s] =node(s,top.g+1,calh(s), pre);   
                }
                swap(s[get(x,y)], s[get(now.first, now.second)]);
            }
        }
    }
    return false;
}

void solve(string s) {
    string t = "12345678 ";
    
    map<string, node> mp;
    cout << s <<endl;
    cout << bfs(s, t, mp) <<endl;;
    
    while(t!="") {
        print(t);
        t = mp[t].pre;
        cout <<endl;
    }
    
    cout << "end" <<endl;
}

int main() {
    
    string b = "87654321 ";
    solve(b);
    return 0;
}

