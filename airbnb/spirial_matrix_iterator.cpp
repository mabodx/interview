#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;


class p{
public:
    int x,y;
    p(){}
    p(int a,int b) {
        x= a;
        y= b;
    }
};

class node{
public:
    vector<string> vc;
    p now;
    vector<vector<bool> > vis;
    int n, m;
    int count = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int dir ;
    node(){}
    node(vector<string> a) {
        dir = 0;
        vc = a;  
        now = p(0,0);
        n = a.size();
        m = a[0].size();
        vis= vector<vector<bool> >(n, vector<bool>(m,false));
    }
    
    bool hasnext(){
        if (valid(now.x, now.y))
            return true;
        return false;
    }
    
    bool valid(int x, int y) {
       // cout << x << " " << y <<endl; 
        if (0 <= x && 0 <= y && x < n && y < m && vis[x][y] == 0) {
            return true;
        }
        return false;
    }
    char next() {
        int n = 4 ;
        
        char ch = vc[now.x][now.y];
        vis[now.x][now.y] = 1;
        while ( n --) {
            int x = now.x + dx[dir];
            int y = now.y + dy[dir];
            if (valid(x, y)) {
                
                now = p(x, y);
                return ch;
            }
            dir = (dir+1)%4;
        }
        now = p(-1,-1);
        return ch;
    }
};

int main() {
 
    vector<string> vc= {
        "abcabc",
        "dgfabc",
        "zcvabc",
        "zcvabc" 
    };
    node a(vc);
    
    while(a.hasnext()) {
        cout << a.next();
    }
    cout <<endl;
    cout<<"Hello";
    return 0;
}
