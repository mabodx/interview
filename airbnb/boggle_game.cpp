/*
board:
{'a', 'b', 'c'},
{'d', 'e', 'f'},
{'g', 'h', 'i'}

dict:
["abc", "cfi", "beh", "defi", "gh"]
*/ 



#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

class node{
public:
    node(){}

    char ch;
    int count = 0 ;
    bool is;
    node(char a) {
        ch = a;
    }
    string s;
    map<char, node *> mp;
};

class Trie{
public:
    node* root;
    Trie(){
        root = new node;
    }
    void insert(string a) {
        node* now = root;
        for (int i = 0; i < a.size(); i++) {
            if (now->mp.find(a[i]) == now->mp.end()) {
                now->mp[a[i]] = new node(a[i]);
            }
            now = now -> mp[a[i]];
        }
        now->is = true;
        now->s=a;
    }
    
};



int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<string> res;
Trie trie;

bool valid(int x, int y, vector<vector<char> >&a, vector<vector<int> >& vis) {
    if (0<=x && x < a.size() && 0 <=y && y < a[x].size() && vis[x][y] == 0)
        return true;
    return false;
}

void dfs(vector<vector<int> >& vis, node* now, int x,int y, vector<vector<char> >&a, vector<string>& ans) {
    if (vis[x][y] == 1)
        return;
    vis[x][y] = 1;

    int n = a.size();
    int m = a[0].size();
    //cout << now->ch <<endl;
    
    if (now -> is) {
        ans.push_back(now->s);
        
        if (ans.size() > res.size()) {
            res = ans;
        }

        for (int i =0 ; i< n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j]==0 && trie.root->mp.find(a[i][j]) != trie.root->mp.end()) {
                    dfs(vis, trie.root->mp[a[i][j]], i, j, a, ans);
                }
            }
        }
        ans.pop_back();
    }
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx,ny, a, vis) &&  now->mp.find(a[nx][ny]) != now->mp.end()) {
            dfs(vis, now->mp[a[nx][ny]], nx, ny, a, ans);
        }
    }
    vis[x][y] = 0;
}


void get(vector<vector<char>> a, vector<string> b) {
    int n = a.size();
    if (n == 0)
        return ;
    int m = a[0].size();
    
    for (string s : b) {
        trie.insert(s);
    }
    
    res.clear();
    
    vector<vector<int> > vis(n, vector<int>(m, 0));
    
    string s;
    vector<string > ans;
    for (int i = 0; i < n; i++) {
        for(int j = 0 ;j < m; j++) 
            if (trie.root->mp.find(a[i][j]) != trie.root->mp.end()) {
               
                dfs(vis,trie.root->mp[a[i][j]], i, j, a, ans);
            }
    }
    cout <<endl;
    for (string s : res) {
        cout << s <<endl;
    }
}


int main() {
    
    vector<vector<char>> vc= 
    {{'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'a', 'b'}};
    
    get(vc, {"ab", "cfd", "beh", "defc", "gh", "ab"});
    //cout<<"Hello";
    return 0;
}
