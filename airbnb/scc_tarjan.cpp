/*
1->2->3->1->4

tarjan(u)
{
    DFN[u]=Low[u]=++Index                      // 为节点u设定次序编号和Low初值
    Stack.push(u)                              // 将节点u压入栈中
    for each (u, v) in E                       // 枚举每一条边
        if (v is not visted)               // 如果节点v未被访问过
            tarjan(v)                  // 继续向下找
            Low[u] = min(Low[u], Low[v])
        else if (v in S)                   // 如果节点v还在栈内
            Low[u] = min(Low[u], DFN[v])
    if (DFN[u] == Low[u])                      // 如果节点u是强连通分量的根
        repeat
            v = S.pop                  // 将v退栈，为该强连通分量中一个顶点
            print v
        until (u== v)
}

*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;


class graph{
public:
    graph(){}
    int n ;
    vector<vector<int>> edges;
    vector<int> vis, low;
    int timestamp;
    
    stack<int> st;
    set<int>inst;
    
    map<int,int> belong;
    int scc = 0;
    graph(int a) {
        n = a;
        for (int i =0 ; i < n; i++) {
            edges.push_back(vector<int>());
        }
        low = vis = vector<int>(a,0);
        scc = 0;
    }
    void insert(int u, int v) {
        edges[u].push_back(v);
    }
    
    
    void tarjan(int u) {
        low[u] = vis[u] = ++timestamp;
        st.push(u);
        inst.insert(u);
        for (int v : edges[u]) {
            if (vis[v]==0) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if(inst.find(v) != inst.end()) {
                low[u] = min(low[u], vis[v]);
            }
        }
        
        if (vis[u] == low[u]) {
            while(!st.empty()) {
                int v= st.top();
                st.pop();
                belong[v] = scc;
                inst.erase(v);
                if(v==u)
                    break;
            }
            scc++;
        }
    }
    
    void find(int n) {
        timestamp = 0;
        
        for (int i = 0; i < n; i++) {
            if(vis[i]==0)
                tarjan(i);
        }
        vector<int> in(scc,0);
        for (int i = 0 ; i < n; i++) {
            for(int j : edges[i]) {
                if (belong[i]!=belong[j])
                   in[belong[j]]++;
            }
            
            cout << i << " belong " << belong[i] <<endl;
        }
        int ans = 0;
        for (int i = 0; i < scc; i++) {
            cout << i << " in " << in[i] <<endl;
            if(in[i] ==0)
                ans++;
        }
        
        
        cout << ans << endl;
    }
    
};

int main() {
    graph a = graph(7);
    
    a.insert(0,6);
    a.insert(1,3);
    a.insert(1,2);
    a.insert(2,4);
    a.insert(3,5);
    a.insert(3,4);

    a.insert(4,1);
    a.insert(4,6);

    a.insert(5,6);
    a.find(7);
    return 0;
}
