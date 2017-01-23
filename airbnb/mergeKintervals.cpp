/*
 [[1, 3], [6, 7]],
  [[2, 4]],
  [[2, 3], [9, 12]]
  
*/ 


#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

class node{
public:
    int x,y;
    int i, j ;
    node(){}
    node(int a, int b) {
        x = a;
        y = b;
    }
    node(int a, int b, int c, int d){
        x = a;
        i = c;
        j = d;
        y = b;
    }
    
};


bool operator <(const node & a, const node & b) {
    if (a.x==b.x)
        return a.y > b.y;
    return a.x > b.x;
}

void mergekinterval(vector<vector<node>> vc) {
    priority_queue<node> q;
    int n=  vc.size();
   
    
    for (int i = 0; i < n; i ++) {
        q.push(node(vc[i][0].x, vc[i][0].y, i, 0));
    }
    
    int is = 0;
    node now;
    node pre(0,0);
    vector<node> ans;
    while(!q.empty()) {
        node nxt = q.top(); q.pop();
        
        cout << pre.x << "pre" << pre.y <<endl;
        
        cout << now.x << "$$" << now.y <<endl;
        
        
        cout << nxt.x << " ** " << nxt.y <<endl; 
        
       
        
        if (nxt.j + 1 < vc[nxt.i].size())
            q.push(node(vc[nxt.i][nxt.j+1].x, vc[nxt.i][nxt.j+1].y, nxt.i, nxt.j+1));
        if (!is) {
            is = 1;
            now = nxt;
        } else {
            if (nxt.x <= now.y) {
                now.y = max(nxt.y, now.y);
                
            } else {
                ans.push_back(node(now.y, nxt.x));
                
                pre = now;
                now = nxt;
            }
        }
    }
    
    for (node a : ans) {
        cout <<  a.x << " " << a.y  << " ;"<<endl;
    }
    cout << endl;
}

int main() {
    
    
    vector<vector<node>> b = {
        {node(1,3), node(6,7), {12, 14}}, 
        {node(2,4)}, 
        {node(2,3), node(9,12)}, 
    };
    mergekinterval(b);
    return 0;
}
